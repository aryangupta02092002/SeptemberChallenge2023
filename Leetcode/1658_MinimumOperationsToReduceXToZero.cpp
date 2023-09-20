class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        int target = sum - x;
        int curr=0, mx=0, start=0;
        bool flag = false;
        
        for(int end=0; end<nums.size(); end++){
            curr += nums[end];
            
            while(start <= end && curr > target){
                curr -= nums[start];
                start += 1;
            }
            if(curr == target){
                flag = true;
                mx = max(mx, end-start+1);
            }
            
        }
        return flag ? nums.size() - mx : -1;
    }
};
