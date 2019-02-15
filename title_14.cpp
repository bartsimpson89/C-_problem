#include<iostream>
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
    ListNode* ReverseList(ListNode* pListHead) {
        ListNode *head = pListHead;
        ListNode *result = NULL;
        while (head)
        {
            ListNode *node = head;
            head = head->next;
            node->next = result;
            result = node;
        }
        return result;
    }

    ListNode* constructList(int data[], int length) {
        ListNode *head = NULL;
        ListNode *list = NULL;
        for (int i=0; i<length; i++)
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
    void printList(ListNode* pListHead)
    {
        while (pListHead)
        {
            cout<<pListHead->val<<" ";
            pListHead = pListHead->next;
        }
        cout<<endl;
    }
};

int main()
{
    Solution solution;
    int data[] = {1,2,3,4,5,6,7,8,9,10};
    ListNode *head = solution.constructList(data, 10);
    head = solution.ReverseList(head);
    solution.printList(head);
    return 0;
}
