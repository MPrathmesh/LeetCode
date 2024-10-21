class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> ans;
        deque<int> dq;

        //First window jo process karo
        for(int i = 0; i < k; i++)
        {
            int element = nums[i];
            //jithe bhi queue k andar chotte elements h remove kardo
            while(!dq.empty() && element > nums[dq.back()])
            {
                dq.pop_back();
            }
            //now insert kardo;
            dq.push_back(i);
        }

        //remaining window ko process karo
        //removal
        //addition

        for(int i = k; i < nums.size(); i++)
        {
            //ans store
            ans.push_back(nums[dq.front()]);

            //removal
            //out of range
            if(!dq.empty() && i - dq.front() >= k)
            {
                dq.pop_front();
            }

            //chote elements pop kardo
            int element = nums[i];
            while(!dq.empty() && element > nums[dq.back()])
            {
                dq.pop_back();
            }

            //addition
            dq.push_back(i); 
        }

        //last window ka answer store karlo
        ans.push_back(nums[dq.front()]);

        return ans;
    }
};