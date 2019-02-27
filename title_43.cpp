#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    string LeftRotateString(string str, int n) {
        string result;
        for (int i=n;i<str.length();i++)
        {
            result += str[i];
        }
        for (int i=0;i<n;i++)
        {
            result += str[i];
        }
        return result;
    }


};



int main()
{
    Solution solution;
    cout<<solution.LeftRotateString("abcxyz123", 1);
    return 0;
}
