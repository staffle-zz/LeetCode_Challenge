class Solution {
public:
    
    int n , m;
    string s , p;
    map<pair<int , int> , bool> mp;
    
    bool recur(int i , int j){
        if(mp.find({i , j}) != mp.end()){
            return mp[{i , j}];
        }
        if(j >= m){
            return mp[{i , j}]  = (i == n);
        }
        if(i == n){
            bool f = 1;
            for(int k = j; k < m; k++){
                if(p[k+1] != '*'){
                    f = 0;
                    break;
                }
                else{
                    k += 1;
                }
            }
            return mp[{i , j}]  = f ;
        }
        
        if(j+1 < m && p[j+1] == '*'){
            bool flag = recur(i , j + 2);
            cout << flag << endl;
            
            for(int k = i; k < n && (p[j] == '.' or s[k] == p[j]) ; k++){
                flag  |= (p[j] == '.' or s[i] == p[j]) && recur(k + 1 , j+2);
                if(flag == 1) break;
            }
            return mp[{i , j}] =  flag;
        }
        else 
            return mp[{i , j}] = (s[i] == p[j] or p[j] == '.') && recur(i+1 , j+1);
        
    }
    bool isMatch(string s, string p) {
        n = s.length() ,  m = p.length();
        this->p = p;
        this->s = s;
        mp.clear();
        return recur(0 , 0);
    }
};
