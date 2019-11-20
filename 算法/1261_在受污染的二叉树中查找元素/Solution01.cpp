/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements
{
    private:
    
        TreeNode* rroot     =   NULL;
        bool      ret_val   =   false;
    
        void __recoverTree(TreeNode* node, int parent_val)
        {
            
            if(node==NULL)
            {
                return;
            }
            
            if(node->left)
            {
                node->left->val = 2*parent_val + 1;
                __recoverTree(node->left,2*parent_val + 1);
            }
            
            if(node->right)
            {
                node->right->val = 2*parent_val + 2;
                __recoverTree(node->right,2*parent_val + 2);
            }
        }
        
        
        void __dfs(TreeNode* node, int target)
        {
            if(node==NULL)
            {
                return;
            }
            
            if(node->val == target)
            {
                ret_val = true;
                return;
            }
            
            
            
            __dfs(node->left,target);
            __dfs(node->right,target);
        }
    
    
    public:
        FindElements(TreeNode* root)
        {
            rroot = root;
            if(root)
            {
                root->val = 0;
                __recoverTree(root,0);
            }
            
            return;
            
        }
        
        bool find(int target)
        {
            ret_val = false;
            
            __dfs(rroot,target);
            
            return ret_val;
            
        }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
 
 
 
/*
执行结果：
通过
显示详情
执行用时 :1288 ms, 在所有 cpp 提交中击败了6.53% 的用户
内存消耗 :17.8 MB, 在所有 cpp 提交中击败了100.00%的用户
 */