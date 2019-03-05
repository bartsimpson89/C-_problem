#include<iostream>
#include<vector>
#include<string>
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
  ListNode *EntryOfLoop(ListNode *pHead)
  {
      vector <ListNode*> vecList;
      ListNode *head1 = pHead;
      ListNode *head2 = pHead;
      while (head1!=NULL && head1->next!=NULL) {
          head1 = head1->next;
          head2 = head2->next->next;

          if (head1==head2) {
              head2 = pHead;
              while (head1!=head2) {
                  head1 = head1->next;
                  head2 = head2->next;
              }
              if (head1 == head2) {
                  return head2;
              }
              
          }
      }
      return NULL;
  }

            
  ListNode* constructList(int data[], int length)
  {
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
    ListNode *head = NULL;
    Solution solution;
    ListNode *node = solution.EntryOfLoop(head);
    return 0;
}


