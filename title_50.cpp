#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        if (length<=1) return false;
        vector<int> number;
        for(int i=0;i<length;i++)
            number.push_back(numbers[i]);
        QuikSort(number, 0, number.size()-1);
        int i = 0;
        for(i=0;i<number.size();i++)
        {
            if(i+1<number.size())
            {
                if(number[i]==number[i+1])
                    break;
            }
        }
        if (i<number.size())
        {
            *duplication = number[i];
            return true;
        }
        return false;



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
    int numbers[]={};
    int data;
    if (solution.duplicate(numbers, 7, &data))
        cout<<data<<endl;
    else
        cout<<"no duplicate"<<endl;
    return 0;
}

