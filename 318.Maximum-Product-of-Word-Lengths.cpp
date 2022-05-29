class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0, N = words.size();
        vector<int> mask(words.size());
        
        for(int i = 0; i < N; ++i)
            for(const char& c : words[i])
                mask[i] |= 1 << (c - 'a');
        
        for(int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j)
                if (!(mask[i] & mask[j]))
                    ans = max(ans, int(words[i].length() * words[j].length()));
        }
        return ans;
    }
};