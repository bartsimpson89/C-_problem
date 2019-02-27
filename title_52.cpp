#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;


class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (str == NULL && pattern == NULL)
            return true;
        else if (str == NULL || pattern == NULL)
            return false;
        string str1(str);
        string str2(pattern);
        return isMatch(str, 0, pattern, 0);
    }


     bool isMatch(string s, int sIdx, string p, int pIdx)
     {
        if (s.length() == sIdx && p.length() == pIdx)
            return true;
         else if (s.length() != sIdx && p.length() == pIdx)
            return false;
         else
         {
             if (pIdx < p.length() - 1 && p[pIdx + 1] == '*')
             {
                if (sIdx < s.length() && (s[sIdx] == p[pIdx] || p[pIdx] == '.'))
                       return isMatch(s, sIdx + 1, p, pIdx + 2) || isMatch(s, sIdx + 1, p, pIdx) || isMatch(s, sIdx, p, pIdx + 2);
                else
                    return isMatch(s, sIdx, p, pIdx + 2);
            }

            if (sIdx < s.length() && (s[sIdx] == p[pIdx] || p[pIdx] == '.'))
                 return isMatch(s, sIdx + 1, p, pIdx + 1);

        }
            return false;
    }
d
};
int main()
{
    Solution solution;
    cout<<solution.match((char *)"aaa",(char *)"a.a")<<endl;
    cout<<solution.match((char *)"aaa",(char *)"a..a")<<endl;
    cout<<solution.match((char *)"aaa",(char *)"ab*ac*a")<<endl;
    cout<<solution.match((char *)"",(char *)".*")<<endl;
    cout<<solution.match((char *)"a",(char *)"a.*")<<endl;
    cout<<solution.match((char *)"a",(char *)".*a")<<endl;
    cout<<solution.match((char *)"a",(char *)"a.*a")<<endl;
    cout<<solution.match((char *)"aa",(char *)"a*")<<endl;
    cout<<solution.match((char *)"aa",(char *)"ab*")<<endl;

    return 0;
}

