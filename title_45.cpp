#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() != 5) return false;
        QuikSort(numbers, 0, numbers.size()-1);
        int zero = 0;
        vector<int> tmp;
        for(int i=0;i<numbers.size();i++)
        {
            if (numbers[i] != 0)
            {
                if( i+1 < numbers.size())
                {
                    if (numbers[i] == numbers[i+1])
                        return false;
                }
                tmp.push_back(numbers[i]);
            }
            else
            {
                zero++;
            }
        }
        int diff = tmp[tmp.size()-1] - tmp[0];
        switch(zero)
        {
            case 0:
                if ( diff != 4)
                    return false;
                else
                    return true;
            case 1:
                if (diff != 4 && diff != 3)
                    return false;
                else
                    return true;
            case 2:
                if (diff != 4 && diff != 3 && diff != 2)
                    return false;
                else
                    return true;
            case 3:
                if (diff != 4 && diff != 3 && diff != 2 && diff != 1)
                    return false;
                else
                    return true;
            case 4:
                return true;
            default:
                return false;
        }



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
    vector<int> numbers = {1,3,0,0,0};
    cout<<"result:"<<solution.IsContinuous(numbers);
    return 0;
}
