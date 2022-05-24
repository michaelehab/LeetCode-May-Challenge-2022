class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> open;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') open.push(i);
            else if(open.size()) {
                // Mark them as Valid
                s[open.top()] = s[i] = 'V';
                open.pop();
            }
        }

        int curr = 0, ans = 0;
        for(int i = 0; i <= s.size(); i++) {
            // Finding longest length of a Valid substring
            if(s[i] == 'V') curr++;
            else {
                ans = max(ans, curr);
                curr = 0;
            }
        }

        return max(curr, ans);
    }
};