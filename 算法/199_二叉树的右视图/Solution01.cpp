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
        vector<int> rightSideView(TreeNode* root)
        {
            vector<int>         ret_vi          ;
            queue<TreeNode*>    qtn             ;
            TreeNode*           temp    = NULL  ;
            int                 num_1   = 0     ;
            int                 num_2   = 0     ;
            int                 i       = 0     ;
            if(root)
            {
                qtn.push(root);
                num_2 = 1;
                num_1 = 0;
                while(num_2)
                {
                    num_1 = num_2;
                    num_2 = 0;
                    for(i=0;i<num_1;i++)
                    {
                        temp = qtn.front();
                        qtn.pop();
                        if(temp->left)
                        {
                            qtn.push(temp->left);
                            num_2++;
                        }
                        if(temp->right)
                        {
                            qtn.push(temp->right);
                            num_2++;
                        }
                    }
                    ret_vi.push_back(temp->val);
                }
            }
            return ret_vi;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 cpp 提交中击败了91.62%的用户
内存消耗 :9.6 MB, 在所有 cpp 提交中击败了41.64%的用户
*/