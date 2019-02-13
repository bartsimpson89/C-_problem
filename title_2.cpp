#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    void replaceSpace(char *str,int length) {
        string strTmp;
        int cnt = 0;
        for (int i=0;i<length;i++)
        {
            if (str[i] == ' ')
            {
                strTmp.append("%");
                strTmp.append("2");
                strTmp.append("0");
            }
            else
                strTmp += str[i];
        }
        memcpy(str, strTmp.c_str(), strTmp.length());
    }
};

int main()
{
    Solution solution;
    char str[30] = "We are happy";
    solution.replaceSpace(str, strlen(str));
    cout<<str<<endl;
}
