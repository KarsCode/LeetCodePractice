class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        string s1;
        vector<string> v1;
        while(getline(ss1,s1,'.'))
        {
            v1.push_back(s1);
        }

        stringstream ss2(version2);
        string s2;
        vector<string> v2;
        while(getline(ss2,s2,'.'))
        {
            v2.push_back(s2);
        }
        
        int i =0,j=0;
        int n1 = v1.size();
        int n2 = v2.size();

        while(i<n1 || j<n2)
        {
            int num1 = (i<n1)? stoi(v1[i]): 0;
            int num2 = (j<n2)? stoi(v2[j]): 0;
            if(num1<num2)return -1;
            else if(num1>num2) return 1;
            i++;
            j++;
        }
        return 0;
    }
};