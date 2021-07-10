#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }

    TreeNode()
    {
        TreeNode(0);
    }
};
int sum(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return root->data + sum(root->left) + sum(root->right);
}
int height(TreeNode *root){
    if (root == NULL)
        return 0;

    return 1+max(height(root->left),height(root->right));
}