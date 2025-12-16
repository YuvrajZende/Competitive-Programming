/*
Shortest Hamiltonian Path (TSP Variant - Bitmask DP)

Problem:
Given a complete weighted graph with n nodes, find the minimum cost path visiting all nodes exactly once (not necessarily returning to start).

Example:
Input: n = 4, dist[][] = {...}
Output: Minimum cost path value.

Concepts Tested:
	•	Bitmask Dynamic Programming
	•	NP-hard reasoning
	•	State compression

State Definition:
dp[mask][i] = min cost to visit set of vertices represented by mask, ending at i

Transition:
dp[mask][i] = min(dp[mask ^ (1 << i)][j] + cost[j][i])

Time Complexity: O(n² * 2ⁿ)
Space Complexity: O(n * 2ⁿ)
*/

