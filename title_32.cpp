#include<iostream>
#include<vector>
#include<stack>
using namespace std;



class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if (numbers.size() == 0) return "";
        vector<string> strResult = Permutation(numbers);
        string min = strResult[0];
        for(int i=1;i<strResult.size();i++)
        {
            if (strResult[i] < min)
                min = strResult[i];
        }
        return min;


    }

    string toString(int num)
    {
        string str;
        while(num)
        {
            string::iterator it = str.begin();
            char ch = num%10+'0';
            str.insert(it, ch);
            num = num/10;
        }
        return str;
    }

    vector<string> Permutation(vector<int> numbers) {
        vector<string> result;
        if (numbers.size() == 0)  return result;
        PermuteString(numbers, 0, numbers.size(), result);
        return result;
    }

    void PermuteString(vector<int> numbers, int k, int m, vector<string> &vecStr)
    {
        if (k == m)
        {
            string str;
            for(int i=0;i<numbers.size();i++)
                str += toString(numbers[i]);
            vecStr.push_back(str);

        }
        else
        {
            for(int i=k; i<m; i++)
            {
                if (i != k && numbers[i] == numbers[k])
                    continue;
                swap(numbers, k, i);
                PermuteString(numbers, k+1, m, vecStr);
                swap(numbers, i, k);
            }
        }
    }
    void swap(vector<int> &str, int i, int j)
    {
        int ch;
        ch = str[j];
        str[j] = str[i];
        str[i] = ch;
    }

};
int main()
{
    vector<int> a={};
    Solution solution;
    cout<<solution.PrintMinNumber(a);
    return 0;

}
