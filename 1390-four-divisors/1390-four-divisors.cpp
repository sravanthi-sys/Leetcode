class Solution {
    int isHavingFourFactors(int n){
        int cnt = 0 ,sum = 0 ,i;
        for(i = 1 ; i * i < n ;i++){
            if(n % i == 0){
                cnt += 2;
                sum += i;
                sum += (n / i);
                cout <<n << " " << i << " " << sum << " " << cnt<< endl;
            }
            if(cnt > 4)return 0;
        }
        if(i * i == n || cnt != 4)return 0;
        return sum;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ;i < nums.size() ;i++){
            int temp = isHavingFourFactors(nums[i]);
            if(temp > 0)sum += temp;
        }
        return sum;
    }
};