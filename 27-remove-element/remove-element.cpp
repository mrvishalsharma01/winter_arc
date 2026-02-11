class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int n=nums.size();
      vector<int>temp;
      for(int i=0; i<n; i++){
        if(nums[i] != val){
            temp.push_back(nums[i]);
        }
      }
      for(int i=0; i<temp.size(); i++){
        nums[i]=temp[i];
      }
      
     return temp.size(); 
      }

};