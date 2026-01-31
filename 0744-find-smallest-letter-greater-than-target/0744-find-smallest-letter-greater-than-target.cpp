class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ind = -1;
        for(int i = 0 ; i < letters.size() ; i ++){
            if(letters[i] > target){
                ind = i;
                break;
            }
        }    
        char ans = letters[0];    
        if(ind < letters.size()){
            ans = letters[ind];
        }
        return ans;
    }
};