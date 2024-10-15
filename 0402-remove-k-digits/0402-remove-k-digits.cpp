class Solution {
public:
    string removeKdigits(string s, int k) {
        const int n = s.size();
        stack<char> st;

        // Iterate through the entire string
        for(int i = 0; i < n; i++) {
            // Remove characters from the stack while the current character is smaller
            while(!st.empty() && k > 0 && st.top() > s[i]) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }

        // If still some removals are left
        while(k > 0){
            st.pop();
            k--;
        }

        // Build the result from the stack
        string res = "";
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        // Reverse the result since the stack pops in reverse order
        reverse(res.begin(), res.end());

        // Remove leading zeros
        while(res.size() > 0 && res[0] == '0') {
            res.erase(res.begin());
        }

        // If the result is empty, return "0"
        if(res.empty()) return "0";

        return res;
    }
};
