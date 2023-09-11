class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans; 
        unordered_map<int, vector<int>> u;
        int sz = groupSizes.size();
      
        for(int i=0; i<sz; i++){
            u[groupSizes[i]].push_back(i);
        }
        for(auto i : u){
            while(i.second.size() > 0){
                vector<int> current;
                for(int j=0; j<i.first; j++){
                    current.push_back(i.second.back());
                    i.second.pop_back();
                }
                ans.push_back(current);   
            }
        }
        return ans;
    }
};
