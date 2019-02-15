#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0) return 0;

        for (int i=0; i<rotateArray.size() - 1; i++) {
            if (rotateArray[i] > rotateArray[i+1])
                return rotateArray[i+1];
        }
        return rotateArray[0];

    }
};



int main()
{
    vector<int> array1 = {1,2,3,4,5};
    vector<int> array2 = {4,5,1,2,3};
    Solution solution;
    cout<<solution.minNumberInRotateArray(array1)<<endl;
    cout<<solution.minNumberInRotateArray(array2)<<endl;
    return 0;
}
