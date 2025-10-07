class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> full; 
        set<int> dryDays;             
        for (int i = 0; i < n; i++) {
            int lake = rains[i];
            if (lake == 0) {
                dryDays.insert(i); 
                continue;
            }
            if (full.count(lake)) {
                auto it = dryDays.lower_bound(full[lake]);
                if (it == dryDays.end()) return {}; 
                ans[*it] = lake; 
                dryDays.erase(it);
            }
            full[lake] = i; 
        }
        for (int i : dryDays) ans[i] = 1;
        return ans;
    }
};
