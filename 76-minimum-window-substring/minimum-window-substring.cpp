class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        vector<int> targetFreq(128, 0);
        for (char c : t) targetFreq[c]++;

        int required = 0;
        for (int i = 0; i < 128; i++)
            if (targetFreq[i] > 0) required++;

        vector<int> windowFreq(128, 0);
        int formed = 0;
        int l = 0, r = 0;
        int minLen = INT_MAX, start = 0;

        while (r < s.size()) {
            char c = s[r];
            windowFreq[c]++;

            if (windowFreq[c] == targetFreq[c])
                formed++;

            // try to shrink the window
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                char lc = s[l];
                windowFreq[lc]--;
                if (windowFreq[lc] < targetFreq[lc])
                    formed--;
                l++;
            }
            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
