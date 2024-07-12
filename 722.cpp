class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        string out ="";
        vector<string> result;

        bool blocked = false;

        for(string line: source)
        {
            for(int i =0;i<line.size();i++)
            {
                if(!blocked)
                {
                    if(i == line.size()-1)
                    {
                        out+=line[i];
                    }
                    else
                    {
                        string temp = line.substr(i,2);
                        if(temp == "/*")
                        {
                            blocked = true;
                            i++;
                        }
                        else if(temp == "//")
                        {
                            break;
                        }

                        else
                        {
                            out+=line[i];
                        }
                    }
                }

                else
                {
                    string temp = line.substr(i,2);
                    if(temp == "*/")
                    {
                        blocked = false;
                        i++;
                    }
                }
            }

            if(!out.empty() && !blocked)
            {
                result.push_back(out);
                out ="";
            }
        }

        return result;
    }
};