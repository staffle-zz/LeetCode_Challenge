class Solution {
public:
    string longestPalindrome(string s) {
        int best_ans = 0;
        string best_str = "";
        int n = s.length();
        for(int i = 0; i < n; i++){
            int k = 0;
            while(i-k>=0 and i+k<n and s[i-k]==s[i+k]) k++;
            k--;
            if(2*k+1 > best_ans)
                best_ans = 2*k+1,best_str = s.substr(i-k,2*k+1);
            k = 1;
            while(i-k+1 >=0 and i+k < n and s[i-k+1]==s[i+k])k++;
            k--;
            if(2*k > best_ans)
                best_ans = 2*k,best_str = s.substr(i-k+1,2*k);
        }
        return best_str;
    }
};
