#include<iostream>
#include<vector>
using namespace std;
class Solution {

public:
    int GetUglyNumber_Solution(int index) {
        int cnt = 1;
        int num = 1;
        vector<int> vecNum;
        vecNum.push_back(num);
        int idxTwo = 0;
        int idxThree = 0;
        int idxFive = 0;
        while(cnt<index)
        {
            int numTwo = vecNum[idxTwo]*2;
            int numThree = vecNum[idxThree]*3;
            int numFive = vecNum[idxFive]*5;
            num = getMin(numTwo, numThree, numFive);
            if (numTwo == num)
                idxTwo++;
            else if(numThree == num)
                idxThree++;
            else
                idxFive++;

            if (vecNum[cnt-1] != num)
            {
                vecNum.push_back(num);
                cnt++;
            }

        }
        return vecNum[cnt-1];

    }
    int getMin(int num1, int num2, int num3)
    {
        int tmp = (num1<num2)?num1:num2;
        return (tmp<num3)?tmp:num3;
    }


};

int main()
{
    Solution solution;
    for(int i=1;i<10;i++)
        cout<<solution.GetUglyNumber_Solution(i);
    cout<<endl;
    return 0;
}
