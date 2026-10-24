class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total=0;
        for(int i =0 ; i < nums.size(); i ++){
            total+=nums[i];
        }

        int leftmostsum = 0 ;

        for(int i = 0 ; i < nums.size() ; i ++){
            int rightmostsum = total - leftmostsum - nums[i];
            if(leftmostsum == rightmostsum){
                return i ;
            }
            leftmostsum += nums[i];
        }

        return -1;
    }
};