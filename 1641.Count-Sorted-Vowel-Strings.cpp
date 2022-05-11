class Solution {
public:
    int countVowelStrings(int n) {
        int starts_a = 1, starts_e = 1, starts_i = 1, starts_o = 1, starts_u = 1;
        for(int i = 2; i <= n; ++i){
            starts_a = starts_a + starts_e + starts_i + starts_o + starts_u;
            starts_e = starts_e + starts_i + starts_o + starts_u;
            starts_i = starts_i + starts_o + starts_u ;
            starts_o = starts_o + starts_u;
        }
        return starts_a + starts_e + starts_i + starts_o + starts_u;
    }
};