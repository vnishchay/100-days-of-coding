#include<bits/stdc++.h> 
using namespace std ; 

// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph
{
public:
 
    // a vector of vectors to represent an adjacency list
    vector<vector<int> > adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        // resize the vector to hold `n` elements of type `vector<int>`
        adjList.resize(n);
 
        // add edges to the directed graph
        for (auto &edge: edges) {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};

// void dijaktras (Graph &graph) {
//        pair<int,int> pp ; 
//        queue<pair<int,int>> q ;
//        vector<int> distance (graph.n , INT_MAX); 
//        q.push_back(0,0); 
//        while(!q.empty()) {
//             int sz  = q.size();
//             auto [f, d] = q.front(); 
//             q.pop();  
//             for(auto a : graph.adjList[f] ) {
//                   if(distance[a] > d + distance[f]) {
//                        distance[a] = d + distance[f]; 
//                   }
//             }
//        } 
       
// }


int main(){
    // vector of graph edges as per the above diagram
    vector<Edge> edges = {
        {0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4},
        {3, 1}, {3, 2}, {4, 3}
    };
 
    // total number of nodes in the graph
    int n = 5;
 
    // build a graph from the given edges
    Graph graph(edges, n);
 
    // check if the graph is not strongly connected or not
    // dijaktras(graph, n); 
 
    return 0;
}