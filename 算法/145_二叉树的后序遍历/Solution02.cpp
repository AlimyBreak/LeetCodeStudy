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
        vector<int> postorderTraversal(TreeNode* root)
        {
            vector<int>         ret_val ;
            stack<TreeNode*>    stnp    ;
            
            TreeNode*           curr    =   root;
            TreeNode*           last    =   NULL;
            
            if(root)
            {
                while(1)
                {
                    while(curr)
                    {
                        stnp.push(curr);
                        curr = curr -> left;
                    }
                    /*遇到NULL回退到上一个节点*/
                    curr = stnp.top();
                    /*回退情况*/
                    if(  (last==curr->right)
                       ||(!curr->right)
                    )
                    {
                        /*从右节点回退或者没有右节点*/
                        stnp.pop();
                        ret_val.push_back(curr->val);    
                        last    =   curr;
                        curr    =   NULL;
                    }
                    else
                    {
                        /*从左节点回退且存在右节点*/
                        curr = curr->right;
                        last = NULL;
                    }
                    
                    /*当前指针为空且栈已经为空则跳出*/
                    if((!curr)&&(stnp.empty()))
                    {
                        break;
                    }
                }
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了83.30% 的用户
内存消耗 :9.1 MB, 在所有 C++ 提交中击败了74.48%的用户
*/