#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr); // next smaller element
        vector<int> pse = findPSE(arr); // previous smaller element
        int total = 0, mod = (int)(1e9 + 7);
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            // Calculate the number of subarrays for which arr[i] is the minimum
            long long left = i - pse[i];
            long long right = nse[i] - i;

            // Update total with contribution of arr[i]
            total = (total + (right * left % mod * arr[i]) % mod) % mod;
        }

        return total;
    }

    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) { // Change <= to >=
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) { // Change n - 1 to n
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }
};
