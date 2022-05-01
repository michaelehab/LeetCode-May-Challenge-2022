// Time : O(n) Space : O(n)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack <char> s1, s2;
        for(char c : s){
            if(c == '#'){
                if(s1.size()) s1.pop();
            }
            else s1.push(c);
        }
        for(char c : t){
            if(c == '#'){
                if(s2.size()) s2.pop();
            }
            else s2.push(c);
        }
        while(s1.size() && s2.size() && s1.top() == s2.top()){
            s1.pop();
            s2.pop();
        }
        return (s1.empty() && s2.empty());
    }
};

// Time : O(n) Space : O(n)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1, s2;
        for(char c : s){
            if(c == '#'){
                if(s1.size()) s1.pop_back();
            }
            else s1 += c;
        }
        for(char c : t){
            if(c == '#'){
                if(s2.size()) s2.pop_back();
            }
            else s2 += c;
        }
        return (s1 == s2);
    }
};

// Time : O(n) Space : O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1, cnt_s = 0, cnt_t = 0;
        while (i >= 0 || j >= 0){
            char s_ch = '#';
            while (i >= 0) {
                if (s[i] == '#'){
                    cnt_s++; 
                    i--; 
                }
                else if (cnt_s == 0 && s[i] != '#'){
                    s_ch = s[i]; 
                    i--; 
                    break;
                }
                else{
                    cnt_s--;
                    i--;
                }
            }
            char t_ch = '#';
            while (j >= 0) {
                if (t[j] == '#'){
                    cnt_t++; 
                    j--;
                }
                else if (cnt_t == 0 && t[j] != '#') {
                    t_ch = t[j]; 
                    j--; 
                    break;
                }
                else{
                    cnt_t--;
                    j--;
                }
            }
            if (s_ch != t_ch) return false;
        }
        return true;
    }
};