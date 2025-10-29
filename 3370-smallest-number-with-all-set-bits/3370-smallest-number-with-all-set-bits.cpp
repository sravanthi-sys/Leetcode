class Solution {
public:
    int smallestNumber(int n) {
        if(n==1){
            return n;
        }
        int i=2;
        while(i*2 <= n){
            i*=2;
        }
        return (i*2)-1;
    }
};