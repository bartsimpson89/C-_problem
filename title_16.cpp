#include <iostream>
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
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot2 == NULL) return false;
        vector<int> root;
        vector<int> subRoot;
        BinaryTreeToVector(pRoot1, root);
        BinaryTreeToVector(pRoot2, subRoot);
        return isSubArray(root, subRoot);
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

    void BinaryTreeToVector(TreeNode *head, vector<int> &vec)
    {
        if (head == NULL)
            return;
        vec.push_back(head->val);// 打印根节点
        BinaryTreeToVector(head->left, vec);
        BinaryTreeToVector(head->right, vec);

    }

    bool isSubArray(vector<int> group, vector<int> subGroup)
    {
        if(subGroup.size() > group.size())
            return false;
        for(int i=0; i<group.size(); i++) {
            int j = 0;
            int index = i;
            for(j = 0; j<subGroup.size(); j++) {
                if(group[index] != subGroup[j]) {
                    break;
                }
                index ++;
            }
            if(j == subGroup.size())
                return true;
        }
        return false;
    }
};

int main()
{
    vector<int> preOrder = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> inOrder = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode *head = NULL;
    Solution solution;
    head = solution.reConstructBinaryTree(preOrder, inOrder);
    solution.printPreOrderBinaryTree(head);

    vector<int> subPreOrder = {2,4,5};
    vector<int> subInOrder = {4,5,2};
    TreeNode *subHead = NULL;
    subHead = solution.reConstructBinaryTree(subPreOrder, subInOrder);
    solution.printPreOrderBinaryTree(subHead);

    cout<<"subTree"<<solution.HasSubtree(head, subHead);
    return 0;



}
