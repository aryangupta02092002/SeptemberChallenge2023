class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low < high){
            if(nums[low] % 2 > nums[high] % 2){
                int tmp = nums[low];
                nums[low] = nums[high];
                nums[high] = tmp;
            }
            
            if(nums[low]%2 == 0){
                low++;
            }
            if(nums[high]%2 == 1){
                high--;
            }
        }
        return nums;
    }
};
