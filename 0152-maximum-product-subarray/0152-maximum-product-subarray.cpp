class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        long long ans = nums[0];
        long long dpMin = nums[0];  // the minimum so far
        long long dpMax = nums[0];  // the maximum so far

        for (int i = 1; i < nums.size(); ++i) {
            const int num = nums[i];
            const long long prevMin = dpMin;  // dpMin[i - 1]
            const long long prevMax = dpMax;  // dpMax[i - 1]

            if (num < 0) {
                dpMin = min(prevMax * num, static_cast<long long>(num));
                dpMax = max(prevMin * num, static_cast<long long>(num));
            } else {
                dpMin = min(prevMin * num, static_cast<long long>(num));
                dpMax = max(prevMax * num, static_cast<long long>(num));
            }

            // Prevent overflow by limiting the range of dpMin and dpMax
            dpMin = max(dpMin, static_cast<long long>(numeric_limits<int>::min()));
            dpMin = min(dpMin, static_cast<long long>(numeric_limits<int>::max()));
            dpMax = max(dpMax, static_cast<long long>(numeric_limits<int>::min()));
            dpMax = min(dpMax, static_cast<long long>(numeric_limits<int>::max()));

            ans = max(ans, dpMax);
        }

        return static_cast<int>(ans);
    }
};