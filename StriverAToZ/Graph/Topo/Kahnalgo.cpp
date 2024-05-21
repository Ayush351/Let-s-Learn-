/*

First, we will calculate the indegree of each node and store it in the indegree array. 
We can iterate through the given adj list, and simply for every node u->v, 
we can increase the indegree of v by 1 in the indegree array.

Initially, there will be always at least a single node whose indegree is 0. 
So, we will push the node(s) with indegree 0 into the queue.

Then, we will pop a node from the queue including the node in our answer array,
and for all its adjacent nodes, we will decrease the indegree of that node by one.
For example, if node u that has been popped out from the queue has an edge towards
 node v(u->v), we will decrease indegree[v] by 1.

After that, if for any node the indegree becomes 0, we will push that node 
again into the queue.

We will repeat steps 3 and 4 until the queue is completely empty. Finally, 
completing the BFS we will get the linear ordering of the nodes in the answer array.

*/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
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
