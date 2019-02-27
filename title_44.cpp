#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    string ReverseSentence(string str) {
        string result;
        vector<string> strSplit;
        strSplit = SplitSentence(str);
        for(int i=strSplit.size()-1; i >= 0; i--)
        {
            result += strSplit[i];
        }
        return result;
    }
    vector<string> SplitSentence(string str)
    {
        string tmp;
        string blank;
        vector<string> result;
        for(int i = 0;i < str.size(); i++)
        {
            if(str[i] != ' ')
            {
                if (blank.length() > 0)
                {
                    result.push_back(blank);
                    blank.clear();
                }
                tmp +=str[i];
            }
            else
            {
                if (tmp.length()>0)
                {
                    result.push_back(tmp);
                    tmp.clear();
                }
                blank += str[i];
            }
        }
        if (tmp.length()>0)
        {
            result.push_back(tmp);
        }
        else if (blank.length()>0)
        {
            result.push_back(blank);
        }

        return result;

    }


};



int main()
{
    Solution solution;
    cout<<solution.ReverseSentence(" I   am a student.  ");
    return 0;
}
