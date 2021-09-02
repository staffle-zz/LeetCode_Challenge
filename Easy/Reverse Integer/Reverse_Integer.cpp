class Solution {
public:
    int reverse(int x) {
        int ax = abs(x);
        bool isNegative = (x < 0);
        string s = to_string(ax);
        std::reverse(s.begin() , s.end());
        int mx = INT_MAX;
        int mn = INT_MIN;
        int ans = -1;
        if(isNegative){
            string mns = to_string(mn).substr(1);
            if(mns.length() == s.length() && mns < s){
                ans = 0;
            }
            else if(mns.length() < s.length()){
                ans = 0;
            }
            else{
                ans = stoi('-'+ s); 
            }
        }
        else{
            string mxs = to_string(mx);
            if(mxs.length() == s.length() && mxs <= s){
                ans = 0;
            }
            else{
                ans = stoi(s); 
            }
        }
        
        return ans;
    }
};
