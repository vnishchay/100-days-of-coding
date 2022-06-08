/*

Given an undirected graph, determine whether it is connected or not. A graph is said to be connected when a path exists between every pair of vertices in the graph.

Input: Graph [edges = [(0, 1), (1, 2), (2, 3), (3, 5), (4, 1)], n = 6]
Output: true

Input: Graph [edges = [(0, 1), (1, 2), (2, 3), (3, 5), (4, 6), (4, 8), (7, 8)], n = 9]
Output: false

Input: Graph [edges = [(0, 1), (1, 3), (2, 3), (3, 5)], n = 6]
Output: false

Constraints:

• The graph is implemented using an adjacency list.
• The maximum number of nodes in the graph is 100, i.e., 0 <= n < 100, and each node is represented by its numeric value.

*/

		// Definition for a Graph
		class Graph
		{
		public:
			// vector of vectors to represent an adjacency list
			vector<vector<int>> adjList;

			// Total number of nodes in the graph
			int n;
		}



class Solution
{
public:

	
    void DFS (Graph const& graph , int src , vector<bool> &visited ) {
    	   visited[src] = true ; 
    	   for(auto a : graph.adjList[src]) {
    	   	     if(!visited[a]) {
    	   	     	 DFS(graph, a , visited); 
    	   	     }
    	   }
    }

	bool isConnected(Graph const &graph)
	{
		  vector<bool> visited(graph.n, false); 
		  DFS(graph, 0 , visited); 
		  for(auto a : visited) {
		  	 if(a == false ) return false ; 
		  }
          return true ; 
	}
};
