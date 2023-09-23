class Solution {
public:
    static bool cmp(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> u;
        int ans = 0;
        sort(words.begin(), words.end(), cmp);

        for(string word : words){
            for(int i=0; i<word.size(); i++){
                string pred = word.substr(0, i) + word.substr(i+1);
                u[word] = max(u[word], u[pred]+1);
            }
            ans = max(ans, u[word]);
        }
        return ans;
    }
};
