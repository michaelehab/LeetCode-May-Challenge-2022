class Solution {
public:
    int numberOfSteps(int num) {
        int total = 0;
        while(num){
            if(num & 1) num--;
            else num /= 2;
            total++;
        }
        return total;
    }
};