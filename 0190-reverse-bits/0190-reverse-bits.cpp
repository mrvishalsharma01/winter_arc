class Solution {
public:
    int reverseBits(int n) {
        unsigned int result = 0; // Use unsigned to handle 32-bit correctly
        
        // Process all 32 bits
        for(int i = 0; i < 32; i++) {
            int bit = n & 1;            // Extract the last bit of n
            result = (result << 1) | bit; // Shift result left and add the extracted bit
            n = n >> 1;                 // Shift n right to process next bit
        }
        
        return result;
    }
};