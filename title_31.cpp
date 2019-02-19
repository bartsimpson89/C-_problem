#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            int num = i;
            while(num)
            {
                if(num%10 == 1)
                    cnt++;
                num=num/10;
            }
        }
        return cnt;


    }
};
int main()
{
    Solution solution;
    cout<<solution.NumberOf1Between1AndN_Solution(14);
    return 0;

}
