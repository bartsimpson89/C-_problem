#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
     int StrToInt(string str) {
        int result = 0;
        for(int i=str.length()-1;i>=0;i--)
        {
            if('0'<=str[i] && str[i]<='9')
            {
                int data = 0;
                data = (str[i]-'0')*Power(10,str.length()-1-i);
                result +=data;
            }
            else if(str[i] == '+' || str[i] == '-')
            {
                result = (str[i] == '+') ? result:-result;
            }
            else
                return 0;
        }

        return result;

    }
    int Power(int base, int n)
    {
        int result = 1;
        for(int i=0;i<n;i++)
        {
            result *= base;
        }
        return result;
    }
};
int main()
{
    Solution solution;
    cout<<solution.StrToInt("123124");
    cout<<endl;
    return 0 ;
}

