/*
翻转一棵二叉树。
示例：
输入：
     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：
     4
   /   \
  7     2
 / \   / \
9   6 3   1
备注:
这个问题是受到 Max Howell 的 原问题 启发的 ：
谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/invert-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void __invertSubTree(struct TreeNode* node)
{
    struct TreeNode* temp = NULL;
    
    if(node==NULL)
    {
        return ;
    }
    
    if(  (node->left==NULL)
       &&(node->right==NULL)
    )
    {
        return;         
    }

    temp        = node->left;
    node->left  = node->right;
    node->right = temp;
    
    if(node->left!=NULL)
    {
        __invertSubTree(node->left);   
    }
    
    if(node->right!=NULL)
    {
        __invertSubTree(node->right);
    }   
}

struct TreeNode* invertTree(struct TreeNode* root)
{
    struct TreeNode* ret_val = root;
    __invertSubTree(root);
    return ret_val;
}

/*
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :7 MB, 在所有 C 提交中击败了100.00%的用户
*/
