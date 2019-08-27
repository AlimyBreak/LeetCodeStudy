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

        TreeNode* __mergeTrees(TreeNode* t1, TreeNode* t2)
        {

            TreeNode*   temp              =   NULL;
            TreeNode*   temp_t1_left      =   NULL;
            TreeNode*   temp_t1_right     =   NULL;
            TreeNode*   temp_t2_left      =   NULL;
            TreeNode*   temp_t2_right     =   NULL;

            if(   (t1==NULL)
                &&(t2==NULL)
            )
            {
                return NULL;
            }

            temp = new struct TreeNode(0);

            if(t1!=NULL)
            {
                temp -> val     +=  t1->val;
                temp_t1_left    =   t1 -> left;
                temp_t1_right   =   t1 -> right;

            }

            if(t2!=NULL)
            {
                temp -> val += t2->val;
                temp_t2_left    =   t2 -> left;
                temp_t2_right   =   t2 -> right;

            }

            temp -> left  = __mergeTrees(temp_t1_left,temp_t2_left);
            temp -> right = __mergeTrees(temp_t1_right,temp_t2_right);
            return temp;
        }

    public:
        TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
        {
            return __mergeTrees(t1,t2);
        }
};

/*
执行结果：
通过
显示详情
执行用时 :92 ms, 在所有 C++ 提交中击败了16.64% 的用户
内存消耗 :22.4 MB, 在所有 C++ 提交中击败了15.45%的用户
*/