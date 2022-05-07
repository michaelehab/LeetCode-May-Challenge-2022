class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int, int>> st;
        int min_left = nums[0];
        for (int i = 1; i < n; ++i) {
            while (!st.empty() && nums[i] >= st.top().first) st.pop();
            if(st.size() && nums[i] > st.top().second) return true;
            st.push({nums[i], min_left});
            min_left = min(min_left, nums[i]);
        }
        return false;        
    }
};