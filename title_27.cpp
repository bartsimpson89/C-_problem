#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        PermuteString(str, 0, str.length(), result);
        return result;
    }

    void PermuteString(string str, int k, int m, vector<string> &vecStr)
    {
        if (k == m)
        {
            vector<string>::iterator it;
            for(it = vecStr.begin(); it != vecStr.end(); it++)
            {
                if (str < *it)
                {
                    vecStr.insert(it, str);
                    break;
                }
            }
            if (it == vecStr.end())
                vecStr.push_back(str);
        }
        else
        {
            for(int i=k; i<m; i++)
            {
                if (i != k && str[i] == str[k])
                    continue;
                swap(str, k, i);
                PermuteString(str, k+1, m, vecStr);
                swap(str, i, k);
            }
        }
    }
    void swap(string &str, int i, int j)
    {
        int ch;
        ch = str[j];
        str[j] = str[i];
        str[i] = ch;
    }
};

int main()
{
    Solution solution;
    string str("abc");
    vector<string> vec = solution.Permutation(str);
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<endl;
    return 0;
}
