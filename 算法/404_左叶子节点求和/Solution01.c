/*
计算给定二叉树的所有左叶子之和。
示例:
    3
   / \
  9  20
    /  \
   15   7
在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
/*
    flag = 0 ;起始根节点
    flag = 1 ;是其父节点的左孩子
    flag = 2 ;是其父节点的有孩子
*/

int left_sum = 0;
void PreOrder(struct TreeNode* treenode,int flag )
{
    if(treenode == NULL)
    {
        return ;
    }
    
    if(( treenode->left == NULL)&&(treenode->right == NULL)&&(flag == 1))
    {
        left_sum += treenode->val;
        return ;   
    }
    PreOrder(treenode->left,1);
    PreOrder(treenode->right,2);
    return ;
}

int sumOfLeftLeaves(struct TreeNode* root)
{
    left_sum = 0;
    PreOrder(root,0);
    return left_sum;
}

/*
令人感动.
102 / 102 个通过测试用例 状态：通过
执行用时:8 ms,提交时间：2 分钟之前
执行用时:8 ms, 在所有C提交中击败了92.13% 的用户 
内存消耗:7.6 MB, 在所有C提交中击败了100.00%的用户 
*/
