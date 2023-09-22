class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tmp = 0;
        for(int i=0; i<t.size(); i++){
            if(s[tmp] == t[i]){
                tmp++;
            }
        }
        if(tmp == s.size()){
            return true;
        }
        return false;
    }
};
