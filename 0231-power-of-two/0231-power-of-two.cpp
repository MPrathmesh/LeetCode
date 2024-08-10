class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Check if n is greater than 0 and (n & (n - 1)) == 0
        if(n > 0 && (n & (n - 1)) == 0) return true;
        else return false;
    }
};
