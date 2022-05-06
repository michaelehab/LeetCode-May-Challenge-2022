class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int count = 1;
        for(int i = 0; i < s.length(); ++i){
            if(!st.empty() && st.top().first == s[i]) count = st.top().second + 1;
            else count = 1;
            st.push({s[i],count});
            if(st.top().second == k){
                for(int j = 0; j < k; ++j) st.pop();
            }
        }
        string ans;
        while(!st.empty()){
            ans += st.top().first;
            st.pop();
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};