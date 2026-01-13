class Solution {
    // double canBeEqual(vector<vector<int>>& squares ,double mid){
        
    //     cout << left <<" " << right << endl;
    //     return abs(right - left) < -1e5;
    // }
public:
    double separateSquares(vector<vector<int>>& squares) {
        long double low = 1e18, high = -1e18;
        for (const auto& sq : squares) {
            low = min(low, static_cast<long double>(sq[1]));
            high = max(high, static_cast<long double>(sq[1] + sq[2]));
        }
        for(int i = 0 ;i < 70 ;i++){
            long double mid = (low + high)/2.0;
            long double left = 0 ,right = 0;
            for(int i = 0 ; i < squares.size() ;i++){
                long double y_bottom = squares[i][1];
                long double y_top = squares[i][1] + squares[i][2];
                if(y_top <= mid){
                    left+= ((long double)squares[i][2] * (long double)squares[i][2]);
                }
                else if(y_bottom >= mid){
                    right+= ((long double)squares[i][2] * (long double)squares[i][2]);
                }
                else{
                    left+=(squares[i][2] * (mid - y_bottom));
                    right+=(squares[i][2] * (y_top - mid));
                }            
            }
            if(right <= left){
                high = mid ;
            }
            else{
                low = mid ;
            }
        }
        return low;
    }
};