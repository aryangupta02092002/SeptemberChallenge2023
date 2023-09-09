class Solution {
public:
    
    int helper(vector<int> &nums, int tar, vector<int> &dp){
        if(tar == 0){
            return 1;
        }
        if(dp[tar] != -1){
            return dp[tar];
        }
        dp[tar] = 0;
        for(int &num : nums){
            if(num <= tar){
                dp[tar] += helper(nums, tar-num, dp);
            }
            
        }
        return dp[tar];
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return helper(nums, target, dp);
    }
};
