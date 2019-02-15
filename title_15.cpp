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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;

        if (pHead1 == NULL && pHead2 == NULL)
            return NULL;

        ListNode *head1 = pHead1;
        ListNode *head2 = pHead2;

        if (head1) //处理头节点
        {
            if (head2->val < head1->val)
            {
                ListNode *tmp = head2;
                head2 = head2->next;
                tmp->next = head1;
                pHead1 = head1 = tmp;
            }
        }
        while (head1)
        {
            if (head2 == NULL)
                break;
            if (head1->next == NULL)
            {
                head1->next = head2;
                break;
            }


            if (head2->val >= head1->val && head2->val < head1->next->val)
            {
                ListNode *tmp = head2; //解开head2的node
                head2 = head2->next;

                ListNode *head1_next = head1->next;//插入head2的node
                head1->next = tmp;
                tmp->next = head1_next;
            }

            head1 = head1->next;
        }
        return pHead1;
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
    int data1[] = {2,4,7,9,10};
    int data2[] = {1,3,5,6,7,11,12,15};
    Solution solution;
    ListNode *node1 = solution.constructList(data1, 5);
    ListNode *node2 = solution.constructList(data2, 8);
    ListNode *node3 = solution.Merge(node1, node2);
    solution.printList(node3);

    return 0;
}
