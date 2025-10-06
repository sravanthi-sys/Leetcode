class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        long long ans = 0;
        int i = 0, j = 0, hcuts = 1, vcuts = 1;
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());
        while(i < m - 1 && j < n - 1){
            // cout << i << " " << j << endl;
            if(horizontalCut[i] >= verticalCut[j]){
                ans += (horizontalCut[i] * vcuts);
                i ++;
                hcuts ++;
            }
            else{
                ans += (verticalCut[j] * hcuts);
                j ++;
                vcuts ++;
            }
        }
        while(i < m - 1){
            ans += (horizontalCut[i] * vcuts);
            i ++;
        }
        while(j < n - 1){
            ans += (verticalCut[j] * hcuts);
            j ++;
        }
        return ans;
    }
};