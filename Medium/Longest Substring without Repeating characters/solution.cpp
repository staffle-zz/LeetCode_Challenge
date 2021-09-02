class Solution {
public:
    bool check(string& s , int len){
        map<char , int> m;
        for(int i = 0; i < len; i++){
            m[s[i]]++;
        }
        if((int)m.size() == len) return true;
        for(int i = len; i < (int)s.length(); i++){
            m[s[i-len]]--; if(m[s[i-len]] == 0) m.erase(s[i-len]);
            m[s[i]]++;
            if((int)m.size() == len){
                return true;
            }
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
       int l = 1 , h = min(100 , (int)s.length());
       int ans = 0;
       while(l <= h){
           int m = (l + h)/2;
           if(check(s , m)){
                ans = max(ans , m);
                l = m + 1;
           }
           else{
               h = m - 1;
           }
       }
       return ans;
    }
};
