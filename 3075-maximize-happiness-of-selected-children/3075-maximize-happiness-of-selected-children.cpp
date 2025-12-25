class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        priority_queue<int ,vector<int> ,greater<>> pq;
        for(int i = 0 ; i < n ;i++){
            pq.push(happiness[i]);
            if(pq.size() > k)pq.pop();
        }
        int remove = k - 1;
        long long ans = 0;
        while(!pq.empty()){
            ans +=max(pq.top() - remove ,0);
            pq.pop();
            remove --;
        }
        return ans;
    }
};