class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        // freq of s1
        for (char c : s1)
            freq1[c - 'a']++;

        // first window freq
        for (int i = 0; i < n; i++)
            freq2[s2[i] - 'a']++;

        if (freq1 == freq2) return true;

        // sliding the window
        for (int i = n; i < m; i++) {
            freq2[s2[i] - 'a']++;         // add new char
            freq2[s2[i - n] - 'a']--;     // remove old char

            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};