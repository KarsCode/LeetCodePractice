class Solution {
public:
    string getString(int d){
        if(d==2)return "abc";
        if(d==3)return "def";
        if(d==4)return "ghi";
        if(d==5)return "jkl";
        if(d==6)return "mno";
        if(d==7)return "pqrs";
        if(d==8)return "tuv";
        if(d==9)return "wxyz";
        return "";
    }
    void backtrack(const string &digits,int index,string&current,vector<string>&result){
        if(index==digits.size()){
            result.push_back(current);
            return;
        }
        string letters=getString(digits[index]-'0');
        for(char letter:letters){
            current.push_back(letter);
            backtrack(digits,index+1,current,result);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>result;
        if(digits.empty())return result;
        string current;
        backtrack(digits,0,current,result);
        return result;
    }
};