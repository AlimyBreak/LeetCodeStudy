/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    private:

        bool ret_val    = true  ;
        int __subtreeDepth(TreeNode* node, int cur_depth)
        {
            int left_depth  = 0     ;
            int right_depth = 0     ;

            if(node==NULL)
            {
                return cur_depth;
            }
            /*如果已经判断出子树存在不平衡的情况就直接返回,不必再递归遍历了*/
            if(ret_val == false)
            {
                return -1;
            }

            /*获取左右子树深度*/
            left_depth  =   __subtreeDepth(node->left,cur_depth+1);
            right_depth =   __subtreeDepth(node->right,cur_depth+1);

            if(abs(left_depth - right_depth) > 1)
            {
                ret_val = false;
            }
            /*如果已经判断出子树存在不平衡的情况就直接返回,不必再递归遍历了*/
            if(ret_val == false)
            {
                return -1;
            }            
            return left_depth>=right_depth?left_depth:right_depth;
        }
    public:
        bool isBalanced(TreeNode* root)
        {
            ret_val = true; /*每次被调用需要进行初始化*/
            __subtreeDepth(root,0);
            return ret_val;
        }
};



/*
执行结果：(https://leetcode-cn.com/submissions/detail/27313132/)
通过
显示详情
执行用时 :20 ms, 在所有 C++ 提交中击败了70.73% 的用户
内存消耗 :16.3 MB, 在所有 C++ 提交中击败了98.08%的用户
*/


