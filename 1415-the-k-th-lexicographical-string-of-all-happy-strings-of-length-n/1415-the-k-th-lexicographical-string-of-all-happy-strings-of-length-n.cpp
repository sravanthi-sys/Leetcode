class Solution {
    int c = 0;
    string res = "";
    void solve(int ind ,int n ,int k ,string temp){
        if(ind == n){
            c++;
            if( c == k)res = temp;
            return ;
        }
        for(char ch = 'a' ; ch <= 'c' ;ch++){
            if(temp.empty() || temp.back() != ch)
            solve(ind + 1,n ,k ,temp + ch);
        }
    }

public:
    string getHappyString(int n, int k) {
        solve(0 , n ,k ,"");
        return res;
    }
};