/*

Construct Adjacency List in such a way that we maintain the list of the inDegree of
the nodes.Also Maintain one vector/array to maintain count of inDegree of each nodes.
If the InDegree Of the particular nodes is "Zero" then we can safely say that those
are the terminal nodes.
Push the terminal nodes in the queue and apply BFS(Kahn Algo)

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    vector<int> calculateKahnBFS(vector<int>adj[],queue<int>q,vector<int>& result,vector<int>& inDegree)
    {
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            result.push_back(node);

            for(auto it:adj[node])
            {
                inDegree[it]--;
                if(inDegree[it]==0)
                {
                    q.push(it);
                }
            }

        }
        return result;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>adj[graph.size()];
        vector<int>inDegree(graph.size(),0);
        //Creating ajacency List For inDegree  of Nodes
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[graph[i][j]].push_back(i);
                inDegree[i]++;
            }

        }
        queue<int>q;

        //pushing terminal nodes to queue
        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i]==0)
            q.push(i);
        }

        vector<int> result;
        result=calculateKahnBFS(adj,q,result,inDegree);
        sort(result.begin(),result.end());
        return result;
        
    }
};
