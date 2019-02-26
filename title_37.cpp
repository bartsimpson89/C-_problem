#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.size() == 0) return 0;
        int index_start = GetFirstK(data, k, 0, data.size()-1);
        int index_end = GetLastK(data, k, 0, data.size()-1);
        cout<<"start"<<index_start;
        cout<<"end"<<index_end;
        cout<<endl;
        if (index_start >= 0 && index_end >= 0 && index_end > index_start)
            return index_end - index_start;
        else if (index_start >= 0 || index_end >= 0)
            return 1;
        else
            return 0;

    }
    int GetFirstK(vector<int> data, int k, int start, int end)
    {
        if (start >= end)
        {
            if (data[start] == k)
            {
                return start;
            }
            else
            {
                return -1;
            }
        }

        if (data[(start+end)/2] > k)
            return GetFirstK(data, k, start, (start+end)/2 - 1);
        else if(data[(start+end)/2] == k )
        {
            int index = (start + end)/2 - 1;
            if (( index >= 0) && data[index] == k)
                return GetFirstK(data, k, start, (start+end)/2 - 1);
            else
            {
                return (start + end)/2;
            }
        }
        else
        {
            return GetFirstK(data, k, (start+end)/2 + 1, end);
        }

    }
    int GetLastK(vector<int> data, int k, int start, int end)
    {
        if (start >= end)
        {
            if (data[start] == k)
                return start + 1;
            else
                return -1;
        }
        if (data[(start+end)/2] > k)
            return GetLastK(data, k, start, (start+end)/2 - 1);
        else if(data[(start+end)/2] == k )
        {
            int index = (start + end)/2 + 1;
            if ((index < data.size()) && data[index] == k)
                return GetLastK(data, k, (start+end)/2 + 1, end);
            else
                return index;
        }
        else
        {
           return GetLastK(data, k, (start+end)/2 + 1, end);
        }

    }
};
int main()
{
    Solution solution;
    vector<int> data={3,3,4,5};
    cout<<solution.GetNumberOfK(data, 3);
    return 0;
}
