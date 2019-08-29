struct TreeNode* searchBST(struct TreeNode* root, int val)
{

    struct TreeNode* temp = root;
    while (1)
    {
        if(temp==NULL)
        {
            break;
        }

        if(temp->val< val)
        {
            temp = temp -> right;
        }
        else if(temp->val > val)
        {
            temp = temp -> left;
        }
        else
        {
            return temp;
        }
    }
    return NULL;
}

/*
执行结果：
通过
显示详情
执行用时 :56 ms, 在所有 C 提交中击败了14.93% 的用户
内存消耗 :16.4 MB, 在所有 C 提交中击败了100.00%的用户
*/



struct TreeNode* searchBST(struct TreeNode* root, int val)
{
    while (1)
    {
        if(root==NULL)
        {
            break;
        }
        if(root->val< val)
        {
            root = root -> right;
        }
        else if(root->val > val)
        {
            root = root -> left;
        }
        else
        {
            return root;
        }
    }
    return NULL;
}

/*
执行结果：
通过
显示详情
执行用时 :36 ms, 在所有 C 提交中击败了68.66% 的用户
内存消耗 :16.6 MB, 在所有 C 提交中击败了100.00%的用户
*/