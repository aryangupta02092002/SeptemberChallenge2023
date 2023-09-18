class Solution {
public:
    unordered_map<int,vector<int>> store;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int low = 0;
        int high = mat[0].size()-1;
        vector<int> result;
        vector<int> answer;
       
        for(int i=0; i<mat.size();i++){
            while(low<=high){
                int mid = low+(high-low)/2;
                if(mat[i][mid]==1){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            result.push_back(low);
            low=0;
            high = mat[0].size()-1;
        }
        
        for(int i=0; i<result.size();i++){
            store[result[i]].push_back(i);
        }
        sort(result.begin(),result.end());
        
        int count=0;
        while(count<k){
            vector<int> temp = store[result[count]];
            for(int j=0;j<temp.size();j++){
                if(count==k) break;
                answer.push_back(temp[j]);
                count++;
            }
        }
        return answer;    
    }
};
