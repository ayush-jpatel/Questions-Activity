class Solution {
public:
    bool visit(vector<int> & visited, vector<vector<int>>& graph, int source, int destination){
        if(source == destination)
            return true;
        if(visited[source] == 1)
            return false;
        visited[source] = 1;
        for(int i=0;i<graph[source].size();i++){
            if(visit(visited,graph,graph[source][i],destination))
                return true;
        }
        return false;
    }
    bool dfs(int n, vector<vector<int>>& edges, int source, int destination){
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n,0);
        return visit(visited,graph,source,destination);

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //trying dfs then bfs later on
        return dfs(n,edges,source,destination);
    }
};