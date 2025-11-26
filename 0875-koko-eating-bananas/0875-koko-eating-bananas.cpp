class Solution {
public:
     bool canEatAll(vector<int>& piles, long long h, long long k) {
        long long hours = 0;
        for (int p : piles) {
            // time for this pile = ceil(p/k)
            hours += (p + k - 1) / k;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canEatAll(piles, h, mid)) {
                ans = mid;        // mid works → try smaller
                high = mid - 1;
            } else {
                low = mid + 1;     // mid too slow → increase speed
            }
        }

        return ans;
    }
};