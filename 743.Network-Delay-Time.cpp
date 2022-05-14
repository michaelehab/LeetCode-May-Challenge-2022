// Dijkstra Algo
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <vector<pair<int, int>>> neighbors(n + 1);
        for(auto t : times) neighbors[t[0]].push_back({t[1], t[2]});
            
        vector <int> timeToReach(n + 1, INT_MAX);
        // Min Heap
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // Starting with the given node
        pq.push({0, k});
        // It takes 0 time to reach the first node
        timeToReach[k] = 0;
        
        while(!pq.empty()){
            int v = pq.top().second;     
            pq.pop();
            
            for(auto n : neighbors[v]){
                if(timeToReach[v] + n.second < timeToReach[n.first]){
                    timeToReach[n.first] = timeToReach[v] + n.second;
                    pq.push({timeToReach[n.first], n.first});
                }
            }
        }
        
        int ans = *max_element(timeToReach.begin() + 1, timeToReach.end());
        
        return ((ans == INT_MAX) ? -1 : ans);
    }
};