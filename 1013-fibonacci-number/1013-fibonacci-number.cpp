class Solution {
public:
    //Plain recursion
    int solveUsingRec(int n) {
        //base case
        if(n == 0 || n == 1) {
            return n;
        }

        //recur relation
        int ans = solveUsingRec(n-1) + solveUsingRec(n-2);
        return ans;
    }

    //Top-down approch
    //rec + memoisation approch
    int solveUsingMem(int n, vector<int> &dp) {
        //base case
        if(n == 0 || n == 1) {
            return n;
        }

        //Step 3: If ans already exist then return ans;
        if(dp[n] != -1) {
            return dp[n]; 
        }

        //recur relation
        //Step 2: - store and return using dp array
        dp[n] = solveUsingMem(n-1, dp) + solveUsingMem(n-2, dp);
        return dp[n];
    }

    int fib(int n) {
        // int ans = solveUsingRec(n);
        // return ans;

        //Step 1: Create dp array
        vector<int> dp(n+1, -1); //first paramter size of array and second initilize with -1
        int ans = solveUsingMem(n, dp);
        return ans;
    }
};