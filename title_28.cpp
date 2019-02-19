#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int halfNum = numbers.size()/2;
        int cnt = 1;
        for(int i=0; i<numbers.size(); i++)
        {
            int num = numbers[i];
            for(int j=i+1;j<numbers.size();j++)
            {
                if (num == numbers[j])
                    cnt++;
            }
            if (cnt>halfNum)
                return num;
            cnt = 1;
        }
        return 0;
    }
};

int main()
{
    vector<int> a={1,2,3,2,2,2,5,4,2};
    Solution solution;
    cout<<solution.MoreThanHalfNum_Solution(a);
    return 0;


}
