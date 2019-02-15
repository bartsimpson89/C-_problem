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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        unsigned int len = 0;
        ListNode *head = pListHead;
        if (head == NULL ) return NULL;
        while (head)
        {
            len++;
            head = head->next;
        }

        head = pListHead;
        if (len < k) return NULL;

        for(unsigned int i=0; (i<len-k) && (head->next != NULL); i++)
        {
            head = head->next;
        }
        return head;
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
};

int main()
{
    Solution solution;
    int data[] = {1,2,3,4,5,6,7,8,9,10};
    ListNode *head = solution.constructList(data, 10);
    cout<< solution.FindKthToTail(head, 2)->val<<endl;
    cout<< solution.FindKthToTail(head, 0)->val<<endl;
    cout<< solution.FindKthToTail(head, 100)->val<<endl;
    return 0;
}
