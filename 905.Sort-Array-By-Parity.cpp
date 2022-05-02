class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int &a, int &b){
            return (a % 2 == 0 && b & 1);
        });
        return nums;
    }
};

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int lastEven = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                int tmp = nums[lastEven];
                nums[lastEven] = nums[i];
                nums[i] = tmp;
                lastEven++ ;
            }
        }  
        return nums;
    }
};