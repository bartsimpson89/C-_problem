#include<iostream>
#include<algorithm>
#include<vector>
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
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vec;
        while (head!=NULL)
        {
            vec.push_back(head->val);
            head = head->next;
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }

    ListNode* constructList(int data[], int length) {
        ListNode *head = NULL;
        ListNode *list = NULL;
        for(int i=0;i<length;i++)
        {
            ListNode *node = new ListNode(data[i]);
            if (i == 0)
                list = head = node;
            else
                list->next = node;
            list = node;
        }
        return head;
    }

};

int main()
{
    int data[10] = {1,2,3,4,5,6,7,8,9,10};
    Solution solution;
    ListNode* head = NULL;
    head = solution.constructList(data, 10);
    vector<int> vec;
    vec = solution.printListFromTailToHead(head);
    for (int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
    cout<<endl;


}
