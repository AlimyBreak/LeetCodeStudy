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
*方法1:常规递归方式
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
int     length  =   0       ;
int*    ret_val =   NULL    ;

void add_ele(int val)
{
    length++;
    ret_val             = (int*)realloc(ret_val,sizeof(int)*length);    /*追加动态空间*/
    ret_val[length-1]   = val;
}

void __preOrder(struct TreeNode* node)
{
    if(node==NULL)
    {
        return;
    }
    
    add_ele     ( node->val   );
    __preOrder  ( node->left  );
    __preOrder  ( node->right );
}



int* preorderTraversal(struct TreeNode* root, int* returnSize)
{    
    if(root==NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    
    ret_val    = malloc(sizeof(int)*1);
    length     = 1;
    ret_val[0] = root->val; /*根*/
    __preOrder(root->left); /*左*/
    __preOrder(root->right);/*右*/
    
    *returnSize = length;
    return ret_val;
}


/*
执行结果：通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了89.42%的用户
内存消耗 :7.8 MB, 在所有 C 提交中击败了56.03%的用户
*/
