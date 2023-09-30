class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int mn = INT_MIN;
        int sz = nums.size();
        stack<int> st;
        
        for(int i=sz-1; i>=0; i--){
            if(nums[i] < mn){
                return true;
            }
            else{
                while(!st.empty() && nums[i] > st.top()){
                    mn = st.top();
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        return false;
    }
};
