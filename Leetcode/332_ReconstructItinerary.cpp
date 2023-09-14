class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> u;
    vector<string> res;
  
    void dfs(string a){
        auto &x = u[a];
        while(!x.empty()){
            string top = x.top();
            x.pop();
            dfs(top);
        }
        res.push_back(a);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {   
        for(auto&x : tickets){
          u[x[0]].push(x[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
