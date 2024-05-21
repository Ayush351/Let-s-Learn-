/*
The topological sorting of a directed acyclic graph is nothing but the linear ordering
 of vertices such that if there is an edge between node u and v(u -> v), 
 node u appears before v in that ordering.

*/

/*

-We must traverse all components of the graph.
-Make sure to carry a visited array(all elements are initialized to 0) and a
stack data structure, where we are going to store the nodes after completing the DFS call.
-In the DFS call, first, the current node is marked as visited. Then DFS call is
 made for all its adjacent nodes.
-After visiting all its adjacent nodes, DFS will backtrack to the previous node and
 meanwhile, the current node is pushed into the stack.
-Finally, we will get the stack containing one of the topological sortings of the graph.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	void dfs(int node, int vis[], stack<int> &st,
	         vector<int> adj[]) {
		vis[node] = 1;
		for (auto it : adj[node]) {
			if (!vis[it]) dfs(it, vis, st, adj);
		}
		st.push(node);
	}
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		int vis[V] = {0};
		stack<int> st;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, vis, st, adj);
			}
		}

		vector<int> ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
};


int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}
