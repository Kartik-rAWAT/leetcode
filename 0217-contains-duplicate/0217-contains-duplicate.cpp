class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>freq;
        int a = 0;
        for(int i = 0 ; i < nums.size(); i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>1){
               a=a+1 ;
            }
        }
       return a>0;
    }
};