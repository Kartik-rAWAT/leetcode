class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum = nums[0];
        int subsum = nums[0];
         for(int i = 1; i < nums.size(); i++){
            currentsum = max(currentsum + nums[i] , nums[i]);
            subsum = max(currentsum , subsum);  
        }
    return subsum;
    }
};