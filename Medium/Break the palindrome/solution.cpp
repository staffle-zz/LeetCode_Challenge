class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.length();
        if( n == 1) 
          return "";
        for(int i = 0; i < n/2; i++){
            if(n%2 == 1 and i == n/2) continue;
            if(s[i] != 'a'){
                s[i] = 'a';
                return s;
            }
        }
        s[n-1] = 'b';
        return s;
    }
};
