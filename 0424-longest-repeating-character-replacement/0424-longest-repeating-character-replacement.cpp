class Solution {
public:
    int characterReplacement(string s, int k) {
    vector<int> freq(26, 0);      // to store frequency of each letter A-Z
    int l = 0;                    // left pointer for sliding window
    int maxFreq = 0;              // highest frequency of one character in current window
    int ans = 0;                  // answer: longest valid substring

    // right pointer moves through the string
    for (int r = 0; r < s.size(); r++) {

        // update frequency of current character
        freq[s[r] - 'A']++;

        // update max frequency so far of any character in the window
        maxFreq = max(maxFreq, freq[s[r] - 'A']);

        // calculate current window size
        int windowSize = r - l + 1;

        // if window is invalid (needs more than k replacements)
        if (windowSize - maxFreq > k) {
            freq[s[l] - 'A']--;   // remove the char at left pointer
            l++;                  // shrink window
        }

        // update answer after adjusting window
        ans = max(ans, r - l + 1);
    }

    return ans;   // return the maximum window size found
}

};