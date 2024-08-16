class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n;  // Total number of subsets (2^n)

        vector<vector<int>> ans;

        for(int i = 0; i < subsets; i++) {  // Iterate through all subsets
            vector<int> li;
            for(int j = 0; j < n; j++) {  // Check each element
                if(i & (1 << j)) {  // Check if the j-th bit in i is set
                    li.push_back(nums[j]);  // Add nums[j] to the current subset
                }
            }
            ans.push_back(li);  // Add the current subset to the answer
        }
        return ans;
    }
};
