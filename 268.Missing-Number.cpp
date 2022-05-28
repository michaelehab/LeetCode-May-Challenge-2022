class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) sum += i;
        return (nums.size() + 1)*(nums.size())/2 - sum;
    }
};