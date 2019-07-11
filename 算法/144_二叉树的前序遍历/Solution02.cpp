/*
给定一个二叉树，返回它的 前序 遍历。
 示例:
输入: [1,null,2,3]  
   1
    \
     2
    /
   3 
输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal
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
 

/*
*方法2:(根左右)迭代方法,需要辅助空间,改用C++
*/
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
    public:
        vector<int> preorderTraversal(TreeNode* root)
        {
            vector<int>                 pv                  ;
            stack<struct TreeNode*>     st                  ;
            TreeNode*                   working_ptr = NULL  ;
            
            if(root==NULL)
            {
                return pv;
            }
            st.push(root);
            while(st.empty()==false)
            {
                working_ptr = st.top();
                st.pop();
                pv.push_back(working_ptr->val);
                if(working_ptr->right!=NULL)        /*根据栈的特性,根左右---那么应该是右孩子先入栈*/
                {
                    st.push(working_ptr->right);
                }
                if(working_ptr->left!=NULL)
                {
                    st.push(working_ptr->left);
                }
            }
            return pv;
        }
};

/*
执行结果：通过
显示详情
执行用时 :8 ms, 在所有 C++ 提交中击败了63.87%的用户
内存消耗 :9 MB, 在所有 C++ 提交中击败了82.75%的用户
*/
