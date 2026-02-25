class Solution {
public:
    static int Nbits(int n){
        int cnt=0;
        while(n!=0){
            n=n & (n-1);
            cnt++;
        }
        return cnt;
    }
    static bool comparator(int a,int b){
        int c1=Nbits(a);
        int c2=Nbits(b);
        if(c1==c2)
        return a<b;

        return c1<c2;
    }
    vector<int> sortByBits(vector<int>& arr) {
      sort(arr.begin(),arr.end(),comparator);
      return arr;
    }
};