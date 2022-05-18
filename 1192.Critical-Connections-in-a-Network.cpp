class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> graph;
    vector<int> firstTime, minTime, visited;
    int time = 1;
    
    void dfs(int node, int parent = -1) {
        firstTime[node] = minTime[node] = time++;
        visited[node] = true;
        
        for(auto& child : graph[node]) {
            if(child == parent) continue;
            if(!visited[child]) dfs(child, node);
            minTime[node] = min(minTime[child], minTime[node]);
            if(firstTime[node] < minTime[child]) ans.push_back({node, child});
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        firstTime.resize(n), minTime.resize(n), visited.resize(n), graph.resize(n);
        for(auto& edge : connections) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(0);
        return ans;
    }
};