class Solution {
public:
    int minimumDeletions(string s) {
     int res=s.length();
     int a_count=0,b_count=0;
     for(int i=0;i<s.length();i++){
        if(s[i]=='a')a_count++;
     }   
        for(int i=0;i<s.length();i++){
            if(s[i]=='a')a_count--;
            res=min(res,b_count+a_count);
            if(s[i]=='b')
            b_count++;    

        }
        return res;
    }
};