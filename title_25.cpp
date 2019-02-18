#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode *head = pHead;
        RandomListNode *clone_head = NULL;
        RandomListNode *clone_list = NULL;
        while(head)
        {
            RandomListNode *node = new RandomListNode(head->label);
            if (head == pHead)
            {
                clone_list = clone_head = node;
            }
            else
            {
                clone_list->next = node;
                clone_list = node;
            }
            head = head->next;
        }


        head = pHead;
        clone_list = clone_head;
        while(head)
        {
            RandomListNode *randHead = pHead;
            int i=0;
            while(randHead)
            {
                if (head->random == randHead)
                    break;
                randHead = randHead->next;
                i++;
            }
            randHead = clone_head;
            for(int j=0;j<i;j++)
            {
                randHead = randHead->next;
            }
            clone_list->random = randHead;

            clone_list = clone_list->next;
            head = head->next;
        }

        return clone_head;
    }
};

int main()
{
    Solution soltion;
    RandomListNode* node1 = NULL;
    RandomListNode* node = soltion.Clone(NULL);
    return 0;

}

