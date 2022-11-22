
// check the relation for DAG

// function of checking cycle in a graph
bool checkCycle(int node, unordered_map<string, list<string> > &adj, unordered_map<string , bool >& visited , unordered_map<string , bool > & dfsvisited) {
    visited[node] = true;
    dfsvisited[node] = true;

    for(auto neighbour: adj[node]){
        if(visited[neighbour]==false){
            bool cycleDetected = checkCycle(neighnour,adj,visited,dfsvisited);
            if(cycleDetected)
                return true;
        }
        else if(dfsvisited[neighbour]){
            return true
        }
    }
    dfsvisited[node] = false;
    return false;
}


// taking no of nodes or vertices 
bool isDAG(int vertices, vector<pair<string,string>> relation)
{
    // No. of nodes or vertices
    int vertices;

    // create a adjacency list for all nodes
    unordered_map<string, list<string> > adj;


    for(int i=0;i<relation.size();i++){
        int u = relation[i].first;
        int v = relation[i].second;

        adj[u].push_back(v);
    }

    // make a visited and dfsvisited map 
    unordered_map<string , bool > visited;
    unordered_map<string , bool > dfsvisited;
    
    for(int i = 1; i <=vertices; i++)
    {
        if(visited[i]==false){
            // call checkcycle function for detect DAG in a given relation 
            if(checkCycle(i, adj, visited, dfsvisited)) {
                return true;
            }
        }
    }
    return false;
}