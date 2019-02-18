#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

using namespace std;



class Solution {

public:
    struct Data{
        int val;
        int floor;
    };
    vector<Data> data;
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<Data> data;
        vector<int> result;
        int floor = 1;
        constructDataFloor(data, root, floor);
        while(1)
        {
            int flag = 0;
            for(int i=0;i<data.size();i++)
            {
                if (data[i].floor == floor)
                {
                    result.push_back(data[i].val);
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                break;
            }
            floor++;
        }
        return result;
    }

    void constructDataFloor(vector<Data> &data, TreeNode *head, int floor)
    {
        if (head == NULL)
            return;
        Data data_tmp;
        data_tmp.val = head->val;
        data_tmp.floor = floor;
        data.push_back(data_tmp);
        floor++;
        constructDataFloor(data, head->left, floor);
        constructDataFloor(data, head->right, floor);
    }

    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int pre_len = pre.size();
        if (pre_len == 0) return NULL;
        TreeNode *node = new TreeNode(pre[0]);
        int vin_len = vin.size();
        int root_index = 0;
        for(int i=0; i<vin_len; i++) {
            if (pre[0] == vin[i]) {
                root_index = i;
                break;
            }
        }

        vector<int> lpre, rpre, lvin, rvin;

        for (int i=1; i<pre_len; i++) {
            if (i<=root_index)
                lpre.push_back(pre[i]);
            else
                rpre.push_back(pre[i]);
        }

        for (int i=0; i<vin_len; i++) {
            if (i == root_index)
                continue;
            else if (i < root_index)
                lvin.push_back(vin[i]);
            else
                rvin.push_back(vin[i]);
        }

        node->left =  reConstructBinaryTree(lpre, lvin);
        node->right = reConstructBinaryTree(rpre, rvin);
        return node;
    }

    void printPreOrderBinaryTree(TreeNode *head)
    {
        if (head == NULL)
            return;
        cout<<head->val<<" ";// 打印根节点
        printPreOrderBinaryTree(head->left);
        printPreOrderBinaryTree(head->right);
    }



};

int main()
{
    vector<int> preOrder = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> inOrder = {4, 7, 2, 1, 5, 3, 8, 6};
    vector<int> result;
    TreeNode *head = NULL;
    Solution solution;
    head = solution.reConstructBinaryTree(preOrder, inOrder);
    result = solution.PrintFromTopToBottom(head);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";

    return 0;
}
