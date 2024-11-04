class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int curr, int prev) {
        //Base case
        if(curr >= nums.size()) {
            return 0;
        }

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solveUsingRecursion(nums, curr+1, curr);
        }
        int exclude = 0 + solveUsingRecursion(nums, curr+1, prev);
        int ans = max(include, exclude);
        return ans;
    }

    int solveUsingMem(vector<int>& nums, int curr, int prev, vector<vector<int> >& dp) {
        //Base case
        if(curr >= nums.size()) {
            return 0;
        }

        //if ans already exist
        if(dp[curr][prev+1] != -1) {
            return dp[curr][prev+1];
        }

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solveUsingMem(nums, curr+1, curr, dp);
        }
        int exclude = 0 + solveUsingMem(nums, curr+1, prev, dp);
        dp[curr][prev+1] = max(include, exclude);
        return dp[curr][prev+1];
    }

    int solveUsingTabulation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> >dp(n+1, vector<int>(n+1, 0));

        for(int curr_index = n-1; curr_index >= 0; curr_index--) {
            for(int prev_index = curr_index-1; prev_index >= -1; prev_index--) {

                int include = 0;
                if(prev_index == -1 || nums[curr_index] > nums[prev_index]) {

                    include = 1 + dp[curr_index+1][curr_index+1];
                }
                int exclude = 0 + dp[curr_index+1][prev_index+1];
                dp[curr_index][prev_index+1] = max(include, exclude);

            }
        }
        return dp[0][0];
    }

    int solveUsingTabulationSO(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int> >dp(n+1, vector<int>(n+1, 0));
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr_index = n-1; curr_index >= 0; curr_index--) {
            for(int prev_index = curr_index-1; prev_index >= -1; prev_index--) {

                int include = 0;
                if(prev_index == -1 || nums[curr_index] > nums[prev_index]) {

                    include = 1 + nextRow[curr_index+1];
                }
                int exclude = 0 + nextRow[prev_index+1];
                currRow[prev_index+1] = max(include, exclude);

            }
            //Shifting
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        // int ans = solveUsingRecursion(nums, curr, prev);
        // return ans;

        //int n = nums.size();
        // vector<vector<int> >dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMem(nums, curr, prev, dp);
        // return ans;

        // int ans = solveUsingTabulation(nums);
        // return ans;

        int ans = solveUsingTabulationSO(nums);
        return ans;
    }
};