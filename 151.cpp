class Solution {
public:
    string reverseWords(string s) {
            auto trim = [](std::string& str) {
            str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
                return !std::isspace(ch);
            }));
            str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
                return !std::isspace(ch);
            }).base(), str.end());
        };
        reverse(s.begin(),s.end());

        int left=0,right=0,i=0;
        int n = s.size();
        while(i<n)
        {   
            while(i<n && s[i]== ' ') i++;
            if(i==n)
            break;
            while(i<n && s[i]!=' ')
            {
                s[right++] = s[i++];
            }
            reverse(s.begin()+left, s.begin()+right);
            s[right++] = ' ';
            left = right;
            i++;

        }
        s.resize(right-1);
        return s;
    }
        
    
};