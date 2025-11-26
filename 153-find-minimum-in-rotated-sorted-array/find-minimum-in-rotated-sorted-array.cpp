class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If mid element is greater than the rightmost,
            // minimum must be to the right side
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // Otherwise, minimum is in the left half including mid
            else {
                right = mid;
            }
        }

        // left == right → minimum element
        return nums[left];
    }
};