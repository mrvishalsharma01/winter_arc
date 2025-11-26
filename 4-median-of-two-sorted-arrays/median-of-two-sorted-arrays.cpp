class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if(A.size() > B.size()) return findMedianSortedArrays(B, A);

        int m = A.size(), n = B.size();
        int totalLeft = (m + n + 1) / 2;

        int low = 0, high = m;

        while(low <= high) {
            int cutA = (low + high) / 2;
            int cutB = totalLeft - cutA;

            int leftA  = (cutA == 0) ? INT_MIN : A[cutA - 1];
            int leftB  = (cutB == 0) ? INT_MIN : B[cutB - 1];
            int rightA = (cutA == m) ? INT_MAX : A[cutA];
            int rightB = (cutB == n) ? INT_MAX : B[cutB];

            if(leftA <= rightB && leftB <= rightA) {
                if((m+n) % 2 == 1)
                    return max(leftA, leftB);

                return (max(leftA,leftB) + min(rightA,rightB)) / 2.0;
            }
            else if(leftA > rightB) {
                high = cutA - 1;
            }
            else {
                low = cutA + 1;
            }
        }
        return 0.0;
    }
};