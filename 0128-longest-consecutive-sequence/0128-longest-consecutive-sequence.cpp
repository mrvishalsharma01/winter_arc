class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {
            // check if num is start of the sequence
            if (!st.count(num - 1)) {
                int current = num;
                int streak = 1;

                // count forward
                while (st.count(current + 1)) {
                    current++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }

        return longest;
    }
};