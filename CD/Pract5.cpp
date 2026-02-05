#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

map<char, vector<string>> grammar, newGrammar;
map<char, set<char>> FIRST, FOLLOW;
map<pair<char,char>, string> table;
set<char> nonTerminals, terminals;
char startSymbol;
const string EPS = "#";

void removeLeftRecursion() {
    cout << "\nGrammar After Removing Left Recursion:\n";

    for (auto &g : grammar) {
        char A = g.first;
        vector<string> alpha, beta;

        for (auto prod : g.second) {
            if (!prod.empty() && prod[0] == A)
                alpha.push_back(prod.substr(1));
            else
                beta.push_back(prod);
        }

        if (!alpha.empty()) {
            char Aprime = tolower(A);
            nonTerminals.insert(Aprime);

            cout << A << " -> ";
            for (int i = 0; i < beta.size(); i++) {
                cout << beta[i] << Aprime;
                if (i < beta.size()-1) cout << " | ";
                newGrammar[A].push_back(beta[i] + string(1, Aprime));
            }
            cout << "\n";

            cout << Aprime << " -> ";
            for (int i = 0; i < alpha.size(); i++) {
                cout << alpha[i] << Aprime << " | ";
                newGrammar[Aprime].push_back(alpha[i] + string(1, Aprime));
            }
            cout << EPS << "\n";
            newGrammar[Aprime].push_back(EPS);
        }
        else {
            newGrammar[A] = g.second;
            cout << A << " -> ";
            for (int i = 0; i < g.second.size(); i++) {
                cout << g.second[i];
                if (i < g.second.size()-1) cout << " | ";
            }
            cout << "\n";
        }
    }
}

void findFirst(char A, set<char>& visited) {
    if (visited.count(A)) return;
    visited.insert(A);

    for (auto prod : newGrammar[A]) {
        if (prod == EPS) {
            FIRST[A].insert('#');
            continue;
        }

        for (int i = 0; i < prod.size(); i++) {
            char X = prod[i];

            if (!isupper(X) && !islower(X)) {
                FIRST[A].insert(X);
                break;
            }
            else {
                findFirst(X, visited);
                for (auto c : FIRST[X])
                    if (c != '#') FIRST[A].insert(c);

                if (!FIRST[X].count('#')) break;
                if (i == prod.size()-1) FIRST[A].insert('#');
            }
        }
    }
}

void computeFirst() {
    for (auto g : newGrammar) {
        set<char> visited;
        findFirst(g.first, visited);
    }
}

void computeFollow() {
    FOLLOW[startSymbol].insert('$');

    bool changed = true;
    while (changed) {
        changed = false;

        for (auto &g : newGrammar) {
            char A = g.first;
            for (auto prod : g.second) {
                for (int i = 0; i < prod.size(); i++) {
                    char B = prod[i];
                    if (!(isupper(B) || islower(B))) continue;
                    if (!newGrammar.count(B)) continue;

                    if (i+1 < prod.size()) {
                        char next = prod[i+1];
                        if (!isupper(next) && !islower(next)) {
                            if (FOLLOW[B].insert(next).second) changed = true;
                        }
                        else {
                            for (auto c : FIRST[next])
                                if (c != '#')
                                    if (FOLLOW[B].insert(c).second) changed = true;
                        }
                    }
                    else {
                        for (auto c : FOLLOW[A])
                            if (FOLLOW[B].insert(c).second) changed = true;
                    }
                }
            }
        }
    }
}

void printSets() {
    cout << "\nFIRST Sets:\n";
    for (auto f : FIRST) {
        cout << "FIRST(" << f.first << ") = { ";
        for (auto x : f.second) cout << x << " ";
        cout << "}\n";
    }

    cout << "\nFOLLOW Sets:\n";
    for (auto f : FOLLOW) {
        cout << "FOLLOW(" << f.first << ") = { ";
        for (auto x : f.second) cout << x << " ";
        cout << "}\n";
    }
}

void buildTable() {
    cout << "\nLL(1) Parsing Table:\n";
    for (auto g : newGrammar) {
        char A = g.first;

        for (auto prod : g.second) {
            set<char> firstSet;
            bool hasEps = true;

            if (prod == EPS) {
                for (auto f : FOLLOW[A]) {
                    table[{A,f}] = prod;
                    cout << "M[" << A << "," << f << "] = " << A << "->" << EPS << "\n";
                }
                continue;
            }

            for (int i = 0; i < prod.size(); i++) {
                char X = prod[i];

                if (!isupper(X) && !islower(X)) {
                    firstSet.insert(X);
                    hasEps = false;
                    break;
                }
                else {
                    for (auto c : FIRST[X])
                        if (c != '#') firstSet.insert(c);
                    if (!FIRST[X].count('#')) {
                        hasEps = false;
                        break;
                    }
                }
            }

            for (auto t : firstSet) {
                table[{A,t}] = prod;
                cout << "M[" << A << "," << t << "] = " << A << "->" << prod << "\n";
            }

            if (hasEps) {
                for (auto f : FOLLOW[A]) {
                    table[{A,f}] = prod;
                    cout << "M[" << A << "," << f << "] = " << A << "->" << prod << "\n";
                }
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number strings";
    cin >> n;

    cout << "Enter productions (# for epsilon):\n";
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        char lhs = s[0];
        if (i == 0) startSymbol = lhs;
        nonTerminals.insert(lhs);

        string rhs = s.substr(2), temp = "";
        for (char c : rhs) {
            if (c == '|') {
                grammar[lhs].push_back(temp);
                temp = "";
            } else temp += c;
        }
        grammar[lhs].push_back(temp);
    }

    removeLeftRecursion();
    computeFirst();
    computeFollow();
    printSets();
    buildTable();
}
/*
E=E+T|T
T=T*F|F
F=(E)|i
*/