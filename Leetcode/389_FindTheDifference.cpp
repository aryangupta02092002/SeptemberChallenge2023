class Solution {
public:
    char findTheDifference(string s, string t) {
        int sz = s.size();
        int sum=0;
        for(int i=0; i<sz; i++){
            sum -= s[i];
            sum += t[i];
        }
        sum += t[s.size()];
        return sum;
    }
};
