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
 
 
 
 void __invertSubTree(struct TreeNode* node_left ,struct TreeNode* node_right)
 {
     
     int temp = 0;
     if(  (node_left==NULL)
        &&(node_right==NULL)
     )
     {
         return;
     }
     
     
     
     
     temp            = node_left->val;
     node_left->val  = node_right->val;
     node_right->val = temp;
     __invertSubTree(node_left->left,node_right->right);
     __invertSubTree(node_left->right,node_right->left);
 }
 
 
struct TreeNode* invertTree(struct TreeNode* root)
{
    struct TreeNode* ret_val = root;
    
    if(root==NULL)
    {
        return ret_val;
    }
    else
    {
        __invertSubTree(root->left,root->right);
        return ret_val;
    }
}

/*
6 / 68 个通过测试用例
状态：解答错误
提交时间：9 分钟之前
输入：
[1,2]
输出：
[1,2]
预期：
[1,null,2]
*/

