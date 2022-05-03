class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector <int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        int sm_i = 1e5 + 1, lg_i = -1e5 - 1;
        bool out_of_order = false;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != tmp[i]){
                sm_i = min(sm_i, i);
                lg_i = max(lg_i, i);
                out_of_order = true;
            }
        }
        if(!out_of_order) return 0;
        return lg_i - sm_i + 1;
    }
};