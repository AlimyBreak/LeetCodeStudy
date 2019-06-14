
/*
给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。

对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

以 10^9 + 7 为模，返回这些数字之和。

      1
   /    \
  0      1
 / \    / \
0   1   0  1


(100) + (101) + (110) + (111) = 4+5+6+7 = 22
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



int ret_sum = 0;
void sumRoot(struct TreeNode* treenode_s , int temp )
{
    if(treenode_s==NULL)
    {
        return;
    }
    if(  (treenode_s->left==NULL)
       &&(treenode_s->right==NULL)
    )
    {
        ret_sum += temp*2 + treenode_s->val;
        return ;
    }
    sumRoot(treenode_s->left,temp*2+treenode_s->val);
    sumRoot(treenode_s->right,temp*2+treenode_s->val);
}


int sumRootToLeaf(struct TreeNode* root)
{
    ret_sum = 0;
    sumRoot(root,0);
    return ret_sum;
}



/*

63 / 63 个通过测试用例 
状态：通过
执行用时：8 ms
提交时间：1 分钟之前


执行用时 :8 ms, 在所有C提交中击败了100.00% 的用户 
内存消耗 :7.9 MB, 在所有C提交中击败了100.00%的用户 

令人感动。

*/




