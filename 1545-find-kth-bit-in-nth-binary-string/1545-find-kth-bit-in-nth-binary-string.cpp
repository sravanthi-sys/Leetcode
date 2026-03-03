class Solution {
    int invertAndRev(int n){
        int inv=0;
        while(n){
            inv=((inv<<1) | !(n%2));
            n/=2;
        }
        cout<<inv<<endl;;
        return inv;
    }
public:
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=1;i<n && k>s.length();i++){
            s+='1';
            string temp=s;
            for(int j=temp.length()-2 ;j>=0;j--){
                char invBit=(temp[j] == '1') ? '0' : '1';
                s+=invBit;
            }
        }
        return s[k-1];
    }
};