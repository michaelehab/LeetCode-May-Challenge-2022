class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(), cmp);
        
        vector<int> lis;
        
        for(auto &i : env){
            int element = i[1];
            
            int idx = (lower_bound(lis.begin(), lis.end(), element) - lis.begin());
            
            if(idx >= lis.size()) lis.push_back(element);
            else lis[idx] = element;
        }
        
        return lis.size();
    }
};