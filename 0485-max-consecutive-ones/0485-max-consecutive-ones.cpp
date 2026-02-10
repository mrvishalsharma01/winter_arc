class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currentCount=0;
        int maxCount=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                currentCount++;
                maxCount=max(maxCount,currentCount);
            }else{
                currentCount=0;
            }
        }
        return maxCount;
    }
};