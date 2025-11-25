#include <queue>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        priority_queue<pair<int,int>> pq; // {num, index}

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});

            if (i >= k - 1) {
                while (pq.top().second <= i - k) pq.pop();
                res.push_back(pq.top().first);
            }
        }

        return res;
    }
};

