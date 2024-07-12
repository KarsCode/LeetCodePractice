#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int resLen = 0;

        for (int i = 0; i < s.length(); i++) {
            // Odd length palindromes centered at i
            int l = i, r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    res = s.substr(l, r - l + 1); // Correct usage of substr
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }

            // Even length palindromes centered between i and i+1
            l = i, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    res = s.substr(l, r - l + 1); // Correct usage of substr
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return res;
    }
};
