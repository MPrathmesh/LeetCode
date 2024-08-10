class Solution {
public:
    int minBitFlips(int start, unsigned goal) {
        return popcount(start ^ goal);
    }
};