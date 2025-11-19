class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
    vector<int> rank(26);

    // Build rank array
    for (int i = 0; i < 26; i++)
        rank[order[i] - 'a'] = i;

    // Compare adjacent words
    for (int i = 0; i < words.size() - 1; i++) {
        string &w1 = words[i];
        string &w2 = words[i + 1];

        int p = 0, q = 0;
        int n1 = w1.size(), n2 = w2.size();

        while (p < n1 && q < n2) {
            if (w1[p] != w2[q]) {
                // wrong order
                if (rank[w1[p] - 'a'] > rank[w2[q] - 'a'])
                    return false;
                // correct order
                break;
            }
            p++;
            q++;
        }

        // prefix case: longer word first → invalid
        if (p == n1 && q == n2) continue;
        if (p == n1) continue;          // w1 finished first → OK
        if (q == n2) return false;      // w2 finished first → wrong
    }

    return true;
}

};