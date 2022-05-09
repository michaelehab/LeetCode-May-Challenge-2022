class Solution {
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.length()) return {};
        
        string state = "";
        vector<string> ans;
        solve(digits, state, ans);
        return ans;
    }
    
    void solve(string digits, string state, vector<string> &ans){
        if(digits.size() == 0) ans.push_back(state);
        else{
            string s = mapping[digits[0] - '0'];   
            digits.erase(digits.begin() + 0);
            for(char c : s) solve(digits, state + c, ans);
        }
    }
};