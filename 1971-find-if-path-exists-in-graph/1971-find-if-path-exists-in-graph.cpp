class Solution {
public:
    bool dfs(int node, int destination,
             vector<vector<int>>& graph,
             vector<bool>& visited) {

        if (node == destination)
            return true;

        visited[node] = true;

        for (int neighbor : graph[node]) {

            if (!visited[neighbor]) {

                if (dfs(neighbor, destination, graph, visited))
                    return true;

            }
        }

        return false;
    }

    bool validPath(int n,
                   vector<vector<int>>& edges,
                   int source,
                   int destination) {

        vector<vector<int>> graph(n);

        for (auto &edge : edges) {

            graph[edge[0]].push_back(edge[1]);

            graph[edge[1]].push_back(edge[0]);

        }

        vector<bool> visited(n, false);

        return dfs(source, destination, graph, visited);
    }
};