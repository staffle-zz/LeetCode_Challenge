class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        int i = 0;
        vector<string> ans(numRows);
        while(i < n){
            for(int j = 0; i < n && j < numRows; j++ , i++){    
                ans[j] += s[i];
            }
            for(int j = numRows - 2; j >= 1 && i < n ; i++ , j--){
                ans[j] += s[i];
            }
        }
        string res = "";
        for(auto i : ans) res += i;
        return res;
    }
};
