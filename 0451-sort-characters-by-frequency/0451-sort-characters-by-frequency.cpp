class Solution {
public:
    string frequencySort(string s) {
        // Using unordered_map for better performance compared to map
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        // Using a max-heap to store characters by their frequency
        priority_queue<pair<int, char>> pq;
        for (auto& it : freqMap) {
            pq.push({it.second, it.first});
        }

        string ans;
        ans.reserve(s.size()); // Pre-allocate memory for the output string

        while (!pq.empty()) {
            auto [freq, ch] = pq.top();
            pq.pop();
            ans.append(freq, ch); // Append 'freq' number of 'ch' to the result
        }

        return ans;
        return ans;
    }
};