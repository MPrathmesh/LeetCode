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

    int solveUsingTabulation(int n) {
        //STEP 1: Create dp array
        vector<int> dp(n+1, -1);
        
        //STEP 2: analyse base case and fill dp array
        dp[0] = 0;
        if(n == 0) return dp[0];
        dp[1] = 1;

        //STEP 3: Fill the remaining dp array
        //size = n + 1;
        //index-> 0 => n
        //index fill ho chuka hai -> 0 and 1
        //baccha konsa index = 2 -> n;
        for(int i = 2; i <= n; i++) {
            //copy paste the recursive logic
            //replace recursive calls with dp array
            //make sure dp array is using looping variable "i"
           dp[i] = dp[i-1] + dp[i-2]; 
        }

        //answer return
        return dp[n]; 
    }

    int solveUsingTabulationSpaceOptimization(int n) {
        int prev = 0;
        if(n == 0) return 0;
        int curr = 1;
        if(n == 1) return 1;

        int ans;
        for(int i = 2; i <= n; i++) {
           ans = curr + prev; 

            //prev and curr lo ek step aage mive kana 
           prev = curr;
           curr = ans;
        }

        //answer return
        return ans; 
    }

    int fib(int n) {
        // int ans = solveUsingRec(n);
        // return ans;

        //Step 1: Create dp array
        // vector<int> dp(n+1, -1); //first paramter size of array and second initilize with -1
        // int ans = solveUsingMem(n, dp);
        // return ans;

        // int ans = solveUsingTabulation(n);
        // return ans;

        return solveUsingTabulationSpaceOptimization(n);
    }
};