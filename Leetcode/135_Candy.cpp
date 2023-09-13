class Solution {
public:
    int candy(vector<int>& ratings) {
        int sz = ratings.size();
        int candy = sz;
        int i=1;

        while(i < sz){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            
            int peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == sz){
                    return candy;
                }
            }
            
            int valley = 0;
            while(i<sz && ratings[i] < ratings[i-1]){
                valley++;
                candy += valley;
                i++;
            }
            
            candy -= min(peak, valley);
        }
        return candy;
    }
};
