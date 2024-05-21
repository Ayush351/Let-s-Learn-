/*

Firstly, we convert the graph into an adjacency list which displays the adjacent nodes for each index represented by a node.
Now, we create a dist array of size N initialized with a very large number which can never be the answer to indicate that initially, all the nodes are untraversed.
Then, perform the standard BFS traversal. 
In every iteration, pick up the front() node, and then traverse for its adjacent nodes.  For every adjacent node, we will relax the distance to the adjacent node if (dist[node] + 1 < dist[adjNode]). Here dist[node] means the distance taken to reach the current node, and ‘1’ is the edge weight between the node and the adjNode. We will relax the edges if this distance is shorter than the previously taken distance. Every time a distance is updated for the adjacent node, we push that into the Queue with the increased distance. 

*/