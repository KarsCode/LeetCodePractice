class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;

        for (char digit : num) {
            while (!res.empty() && k > 0 && res.back() > digit) {
                res.pop_back();
                k--;
            }
            res.push_back(digit);
        }

        // Handle case where k > 0, remove remaining k digits from the end
        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }

        // Remove leading zeros
        int start = 0;
        while (start < res.size() && res[start] == '0') {
            start++;
        }

        // If all characters are zeros, return "0"
        if (start == res.size()) {
            return "0";
        }

        return res.substr(start);
    }
};