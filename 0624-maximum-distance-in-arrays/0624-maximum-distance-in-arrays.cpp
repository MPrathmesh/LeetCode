class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int mn = 10000;
        int mx = -10000;

        for(const vector<int>& a : arrays) {
            ans = max({ans, a.back() - mn, mx - a.front()});
            mn = min(mn, a.front());
            mx = max(mx, a.back());
        }

        return ans;
    }
};