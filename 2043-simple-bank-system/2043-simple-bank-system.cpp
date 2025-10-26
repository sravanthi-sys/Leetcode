class Bank {
    int n;
    vector<long long> bal;
public:
    Bank(vector<long long>& balance) {
        n = balance.size();
        bal.resize(n);
        for(int i = 0 ; i < n ; i ++){
            bal[i] = balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        int i = account1 - 1, j = account2 - 1;
        if(i >= 0 && j >= 0 && i < n && j < n && bal[i] >= money){
            bal[j] += money;
            bal[i] -= money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        int i = account - 1;
        if(i >= 0 && i < n){
            bal[i] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        int i = account - 1;
        if(i >= 0 && i < n && bal[i] >= money){
            bal[i] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */