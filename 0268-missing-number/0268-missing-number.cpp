class Solution {
public:
    int missingNumber(vector<int>& nums) {
         int n = nums.size();
        int xorAll = 0;

        // XOR numbers from 0 to n
        for(int i = 0; i <= n; i++) {
            xorAll ^= i;
        }

        // XOR all numbers in the array
        for(int num : nums) {
            xorAll ^= num;
        }

        return xorAll;
    }
};