class Solution {
public:
    int hammingWeight(uint32_t n) {
        int total = 0;
        for(int i = 0; i < 32; i++) if(n & 1<<i) total++;
        return total;
    }
};