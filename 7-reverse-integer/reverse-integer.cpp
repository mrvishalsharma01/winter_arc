class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while(x != 0) {
            int pop = x % 10;  // Get the last digit
            x /= 10;           // Remove last digit

            // Check for overflow before multiplying by 10
            if(rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) return 0;
            if(rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) return 0;

            rev = rev * 10 + pop; // Append digit
        }

        return rev;
    }
};