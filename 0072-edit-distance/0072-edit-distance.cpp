class Solution {
public:
    int solveUsingRecursion(string& a, string& b, int i, int j) {
        //base case
        if(i == a.length()) {
            return b.length()-j;
        }
        if(j == b.length()) {
            return a.length()-i;        
        }

        int ans = 0;
        if(a[i] == b[j]) {
            ans = 0 + solveUsingRecursion(a, b, i+1, j+1);
        }
        else {
            int replace = 1 + solveUsingRecursion(a, b, i+1, j+1);
            int insert = 1 + solveUsingRecursion(a, b, i, j+1);
            int remove = 1 + solveUsingRecursion(a, b, i+1, j);
            ans = min(insert, min(remove, replace));
        }
        return ans;
    }

    int solveUsingMem(string& a, string& b, int i, int j, vector<vector<int> >& dp) {
        //base case
        if(i == a.length()) {
            return b.length()-j;
        }
        if(j == b.length()) {
            return a.length()-i;        
        }

        //check if ans already exist
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        if(a[i] == b[j]) {
            ans = 0 + solveUsingMem(a, b, i+1, j+1, dp);
        }
        else {
            int replace = 1 + solveUsingMem(a, b, i+1, j+1, dp);
            int insert = 1 + solveUsingMem(a, b, i, j+1, dp);
            int remove = 1 + solveUsingMem(a, b, i+1, j, dp);
            ans = min(insert, min(remove, replace));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveUsingTabulation(string a, string b) {
        //Step 1 - Create dp Array
        vector<vector<int> >dp(a.length()+1, vector<int>(b.length()+1, -1));

        //Step 2 - Analysis Base and case and insert the answer
        for(int col = 0; col <= b.length(); col++) {
            dp[a.length()][col] = b.length()-col;
        }
        for(int row = 0; row <= a.length(); row++) {
            dp[row][b.length()] = a.length()-row;
        }

        for(int i_index = a.length()-1; i_index >= 0; i_index--) {
            for(int j_index = b.length()-1; j_index >= 0; j_index--) {
                int ans = 0;
                if(a[i_index] == b[j_index]) {
                    ans = 0 + dp[i_index+1][j_index+1];
                }
                else {
                    int replace = 1 + dp[i_index+1][j_index+1];
                    int insert = 1 + dp[i_index][j_index+1];
                    int remove = 1 + dp[i_index+1][j_index];
                    ans = min(insert, min(remove, replace));
                }
                dp[i_index][j_index] = ans;   
            }
        }

        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        // int ans = solveUsingRecursion(word1, word2, i, j);
        // return ans;

        // vector<vector<int> > dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        // int ans = solveUsingMem(word1, word2, i, j, dp);
        // return ans;

        int ans = solveUsingTabulation(word1, word2);
        return ans;
    }
};