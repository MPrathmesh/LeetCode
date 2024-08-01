class Solution {
public:
    int countSeniors(vector<string>& details) {
        //Use ranges::count_if to ciunt elements satisfying the given condition
        return ranges::count_if(details, [](const string& detail) {
            //Extract the substring conatining the age and convert it to an integer
            return stoi(detail.substr(11, 2)) > 60;
        });
    }
};