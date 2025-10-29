class Solution {
public:
    int smallestNumber(int n) {
        if(n == 1)return n;
        int power = log2(n);
        return pow(2, power + 1) - 1;
    }
};