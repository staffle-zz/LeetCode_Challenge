class Solution {
public:
    int myAtoi(string str) {
        int n = str.length();
        if(n == 0){
            return 0;
        }
        int ret = 0, sign = 1, i = 0, base = INT_MAX / 10;
        while(i < n && str[i] == ' ') i++;
        
        if (i < n && (str[i] == '+' || str[i] == '-')) sign = str[i++] == '+' ?: -1;
        while (i < n && isdigit(str[i])) {
            if (ret > base || (ret == base && str[i] - '0' > 7)) 
                return sign > 0 ? INT_MAX : INT_MIN;
            ret = 10 * ret + (str[i++] - '0');
        }
        return sign * ret;
    }
};
