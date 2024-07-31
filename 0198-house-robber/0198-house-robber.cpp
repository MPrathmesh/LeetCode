class Solution {
public:
    int solveUsingRecursion(vector<int> &nums, int index) {
        //Base case
        if(index >= nums.size()) {
            return 0; 
        }
        //recursive relation
        int include = nums[index] + solveUsingRecursion(nums, index+2);
        int exclude = 0 + solveUsingRecursion(nums, index + 1);
        int ans = max(include, exclude);
        return ans;
    }

    int solveUsingMem(vector<int> &nums, int index, vector<int> &dp) {
        //Base case
        if(index >= nums.size()) {
            return 0; 
        }

        //has already exist in dp
        if(dp[index] != -1) {
            return dp[index];
        }

        //recursive relation
        int include = nums[index] + solveUsingMem(nums, index+2, dp);
        int exclude = 0 + solveUsingMem(nums, index + 1,dp);
        dp[index] = max(include, exclude);
        return dp[index];
    }

    int rob(vector<int>& nums) {
        int index = 0;
        // int ans = solveUsingRecursion(nums, index);
        // return ans;
        int n = nums.size();
        vector<int> dp(n+1, -1);
        int ans = solveUsingMem(nums, index, dp);
        return ans;
    }
};