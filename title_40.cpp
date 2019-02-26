#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size()<2) return;

        QuikSort(data, 0, data.size() - 1);
        int preValue = data[0];
        int cnt = 1;
        int *result[2] = {num1,num2};
        int index = 0;
        for (int i=1; i<data.size(); i++)
        {

            if(preValue == data[i])
            {
                cnt++;
                continue;
            }
            if (cnt == 1)
            {
                *result[index++] = preValue;
            }
            cnt = 1;
            preValue = data[i];
            if (index == 2) break;
        }
        if (index == 1)
        {
            *result[1] = data[data.size()-1];
        }
        return;

    }

    void QuikSort(vector<int> &input, int start, int end)
    {
        if(start>end) return;
        int base = input[start];
        int j = end;
        int i = start;
        while(i!=j)
        {
            while(input[j]>=base && i < j)
                j--;
            while(input[i]<=base && i < j)
                i++;

            if (i < j)
            {
                int k = input[j];
                input[j] = input[i];
                input[i] = k;
            }
        }
        int k = input[start];
        input[start] = input[i];
        input[i] = k;

        QuikSort(input, start, i-1);
        QuikSort(input, i+1, end);
    }
};



int main()
{
    Solution solution;
    vector<int> data={4,6,2,2,3,3,8,8,9,9,1000000,1000000};
    int num1,num2;
    solution.FindNumsAppearOnce(data, &num1, &num2);
    cout<<"num1:"<<num1;
    cout<<"num2:"<<num2;
    cout<<endl;

    return 0;
}
