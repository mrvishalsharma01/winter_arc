class Solution {
public:
    int lengthOfLastWord(string s) {
    int i = s.length() - 1;
    int length = 0;

    while (i >= 0 && s[i] == ' ') i--;      // skip spaces
    while (i >= 0 && s[i] != ' ') {         // count letters
        length++;
        i--;
    }

    return length;
}

};