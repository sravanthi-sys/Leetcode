class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, 
    vector<vector<int>>& queries) {
        unordered_map<int, int> groupNo;
        unordered_map<int, set<int>> groups;
        vector<vector<int>> adj(c + 1, vector<int>());
        for(int i = 0 ; i < connections.size() ;i++){
            int u = connections[i][0], v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int compoNo = 0;
        vector<bool> vis(c + 1, false);
        for(int i = 1 ; i <= c ;i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i] = true;
                set<int> component;
                while(!q.empty()){
                    int node = q.front();
                    groupNo[node] = compoNo;
                    component.insert(node);
                    q.pop();
                    for(auto it : adj[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it] = true;
                        }
                    }
                }
                groups[compoNo] = component;
                compoNo ++;
            }
        }
        vector<int> ans;
        unordered_set<int> offline;
        for(int i = 0 ; i < queries.size() ; i++){
            int x = queries[i][1];
            int grpno = groupNo[x];
            if(queries[i][0] == 2){
                groups[grpno].erase(x);
                offline.insert(x);
            }
            else{
                ans.push_back(-1);
                if(offline.find(x) == offline.end()){
                    ans.back() = x;
                }
                else if(groups[grpno].size() > 0){
                    ans.back() = *(groups[grpno].begin());
                }
            }
        }
        return ans;
    }
};