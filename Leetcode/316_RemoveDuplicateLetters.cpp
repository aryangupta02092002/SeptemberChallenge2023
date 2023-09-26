class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> u;
        unordered_map<char, bool> vis;
        for(int i=0; i<s.size(); i++){
            u[s[i]]++;
        }
        string ans;
        for(int i=0; i<s.size(); i++){
            u[s[i]]--;
            if(vis[s[i]]){
                continue;
            }
            while(ans.empty() == false && ans.back() > s[i] && u[ans.back()] > 0){
                vis[ans.back()] = false;
                ans.pop_back();
            }
            vis[s[i]] = true;
            ans += s[i];
        }
        return ans;
    }
};
