class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        if(milestones.size() == 1)return 1;
        long long maxi = *max_element(milestones.begin(), milestones.end());
        long long rem = accumulate(milestones.begin(), milestones.end(), 0LL);
        rem -= maxi;
        if(maxi - rem <= 0)return maxi + rem;
        return rem + rem + 1;
    }
};