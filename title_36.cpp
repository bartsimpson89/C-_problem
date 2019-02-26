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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL)
            return NULL;
        ListNode *head1 = pHead1;
        ListNode *head2 = pHead2;
        while(head1)
        {
            head2 = pHead2;
            while(head2)
            {
                if (head1 == head2)
                    break;
                head2 = head2->next;
            }
            if (head2 != NULL)
                break;
            head1 = head1->next;
        }
        if (head1 == NULL)
            return NULL;
        return head1;

    }
};

int main()
{
    Solution solution;
    solution.FindFirstCommonNode(NULL, NULL);
    return 0;
}
