#include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> grammar;
set<char> terminals, nonTerminals;
map<char, set<char>> FIRSTVT, LASTVT;
map<pair<char,char>, char> table;
set<char> visitedFirst, visitedLast;

void findFirstVT(char A) {
    if (visitedFirst.count(A)) return;
    visitedFirst.insert(A);

    for (auto prod : grammar[A]) {
        if (!isupper(prod[0]))
            FIRSTVT[A].insert(prod[0]);

        else {
            if (prod.size() > 1 && !isupper(prod[1]))
                FIRSTVT[A].insert(prod[1]);

            findFirstVT(prod[0]);
            for (auto x : FIRSTVT[prod[0]])
                FIRSTVT[A].insert(x);
        }
    }
}

void findLastVT(char A) {
    if (visitedLast.count(A)) return;
    visitedLast.insert(A);

    for (auto prod : grammar[A]) {
        int n = prod.size();

        if (!isupper(prod[n-1]))
            LASTVT[A].insert(prod[n-1]);

        else {
            if (n > 1 && !isupper(prod[n-2]))
                LASTVT[A].insert(prod[n-2]);

            findLastVT(prod[n-1]);
            for (auto x : LASTVT[prod[n-1]])
                LASTVT[A].insert(x);
        }
    }
}


// ---------- Build Precedence Table ----------
void buildTable() {
    for (auto g : grammar) {
        for (auto prod : g.second) {
            for (int i = 0; i < prod.size() - 1; i++) {

                if (!isupper(prod[i]) && !isupper(prod[i+1]))
                    table[{prod[i], prod[i+1]}] = '=';

                if (!isupper(prod[i]) && isupper(prod[i+1]))
                    for (auto x : FIRSTVT[prod[i+1]])
                        table[{prod[i], x}] = '<';

                if (isupper(prod[i]) && !isupper(prod[i+1]))
                    for (auto x : LASTVT[prod[i]])
                        table[{x, prod[i+1]}] = '>';
            }
        }
    }
}

// ---------- Get Top Terminal ----------
char topTerminal(stack<char> st) {
    while (!st.empty()) {
        if (!isupper(st.top())) return st.top();
        st.pop();
    }
    return '$';
}

// ---------- Reduce ----------
bool reduce(stack<char> &st) {
    vector<char> handle;
    char right = st.top(); 
    st.pop();
    handle.push_back(right);

    // Find handle boundary using precedence
    while (true) {
        char left = st.top();
        if (table[{left, right}] == '<') break;

        right = left;
        handle.push_back(right);
        st.pop();
    }

    reverse(handle.begin(), handle.end());
    string h(handle.begin(), handle.end());

    for (auto g : grammar) {
        for (auto p : g.second) {
            if (p == h) {
                st.push(g.first);
                bool changed = true;
                while (changed) {
                    changed = false;
                    char top = st.top();
                    for (auto g2 : grammar) {
                        for (auto p2 : g2.second) {
                            if (p2.size() == 1 && p2[0] == top && g2.first != top) {
                                st.pop();
                                st.push(g2.first);
                                changed = true;
                            }
                        }
                    }
                }
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    cout << "Enter productions (E->E+T format):\n";
    for (int i = 0; i < n; i++) {
        string prod;
        cin >> prod;
        char lhs = prod[0];
        string rhs = prod.substr(3);

        nonTerminals.insert(lhs);

        stringstream ss(rhs);
        string part;
        while (getline(ss, part, '|')) {
            grammar[lhs].push_back(part);
            for (char c : part)
                if (!isupper(c)) terminals.insert(c);
        }
    }
    terminals.insert('$');

    for (auto nt : nonTerminals) {
        findFirstVT(nt);
        findLastVT(nt);
    }

    buildTable();
    char start = grammar.begin()->first;

    for (auto t : FIRSTVT[start])
        table[{'$', t}] = '<';

    for (auto t : LASTVT[start])
        table[{t, '$'}] = '>';

    table[{'$', '$'}] = '=';


    // Display Table
    cout << "\nOperator Precedence Table:\n   ";
    for (char t : terminals) cout << t << " ";
    cout << "\n";
    for (char r : terminals) {
        cout << r << " ";
        for (char c : terminals) {
            if (table.count({r,c})) cout << table[{r,c}] << " ";
            else cout << ". ";
        }
        cout << "\n";
    }

    // Parsing
    string input;
    cout << "\nEnter input string: ";
    cin >> input;
    input += "$";

    stack<char> st;
    st.push('$');

    cout << "\nStack\tInput\tAction\n";

    int i = 0;
    while (true) {
        char a = topTerminal(st);
        char b = input[i];

        string s = "";
        stack<char> temp = st;
        while (!temp.empty()) {
            s = temp.top() + s;
            temp.pop();
        }
        cout << s << "\t" << input.substr(i) << "\t";

        if (table[{a,b}] == '<' || table[{a,b}] == '=') {
            cout << "Shift\n";
            st.push(b);
            i++;
        }
        else if (table[{a,b}] == '>') {
            if (reduce(st)) cout << "Reduce\n";
            else { cout << "Error\n"; break; }
        }
        else if (a == '$' && b == '$') {
            cout << "Accepted\n";
            break;
        }
        else {
            cout << "Rejected\n";
            break;
        }
    }
}
