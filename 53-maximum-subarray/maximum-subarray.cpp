class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsub=nums[0],currsum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(currsum+nums[i]>nums[i]){
                currsum=currsum+nums[i];
            }
            else{
                currsum=nums[i];
            }
            maxsub=max(maxsub,currsum);
        }
        return maxsub;
    }
};