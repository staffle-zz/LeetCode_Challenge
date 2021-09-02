class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
      int base1 = 10 , base2 = 1;
        while(1){
            if(x/base2 <= 9){
                break;
            }
            base2 *= 10;
        }
        int nx = x , ny = x;
        while(nx != 0){
            int d1 = nx%10;
            nx /= 10;
            int d2 = ny/base2;
            ny = ny%base2;
            base2 /= 10;
            if(d1 != d2) return false;
        }
        return true;
    }
};
