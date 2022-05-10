class Solution {
    vector<vector<int>> ans;
public:
    
    int sum(vector<int>& comb){
        int total = 0;
        for(const int & x : comb) total += x;
        return total;
    }
    
    void solve(int k, int n, vector<int>& comb, int num){
        if(k == 0){
            if(sum(comb) == n){
                ans.push_back(comb);
            }
            return;
        }
        
        if(num > 9) return;
        
        comb.push_back(num);
        solve(k - 1, n, comb, num + 1);

        comb.pop_back();
        solve(k, n, comb, num + 1);    
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> comb;
        combSumHelper(k, n, comb, 1);
        return ans;
    }
};