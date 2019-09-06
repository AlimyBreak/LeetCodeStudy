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
        int ret_val     = 0;
        int target_sum  = 0;
        
        void __pathSum(TreeNode* node , int level_sum)
        {
            if(node==NULL)
            {
                return ;
            }
            
            int temp = level_sum + node->val;
            
            if(temp==target_sum)
            {
                ret_val++;
                //return;
            }
            __pathSum(node->left,temp);
            __pathSum(node->right,temp);
        }
    public:
        int pathSum(TreeNode* root, int sum)
        {
            ret_val     = 0;
            target_sum  = sum;
            queue<TreeNode*>    qtn     ;
            TreeNode*           temp    ;
            if(root!=NULL)
            {
                qtn.push(root);
                while(!qtn.empty())
                {
                    temp = qtn.front();
                    qtn.pop();
                    __pathSum(temp,0);
                    if(temp->left)
                    {
                      qtn.push(temp->left);
                    }
                    if(temp->right)
                    {
                        qtn.push(temp->right);
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
执行用时 :40 ms, 在所有 C++ 提交中击败了49.50% 的用户
内存消耗 :14.5 MB, 在所有 C++ 提交中击败了93.90%的用户
*/