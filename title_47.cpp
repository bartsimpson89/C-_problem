#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
      int Sum_Solution(int n) {
        return Sum(0,n);

    }

    int Sum(int i, int n)
    {
        if (i == n)
            return n;
        i++;
        return i-1+Sum(i,n);
    }





};



int main()
{
    Solution solution;
    cout<<"result:"<<solution.Sum_Solution(1);
    return 0;
}
