class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int ans = 0;
        for(int &i : nums){
            if(freq[k - i] > 0){
                ans++; 
                freq[k - i]--;
            }
            else freq[i]++;
        }
        return ans;
    }
};