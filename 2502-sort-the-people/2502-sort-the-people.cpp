class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string>ans;
        vector<pair<int, string>>mp;

        int n = names.size();
        for(int i = 0; i < n; i++) {
            mp.push_back({heights[i], names[i]});
        }

        sort(mp.begin(), mp.end(), greater<>());

        for(auto i:mp) {
            ans.push_back(i.second);
        }

        return ans;
    }
};