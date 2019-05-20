/*
在大小为 2N 的数组 A 中有 N+1 个不同的元素，其中有一个元素重复了 N 次。
返回重复了 N 次的那个元素。
示例 1：
输入：[1,2,3,3]
输出：3
示例 2：
输入：[2,1,2,5,3,2]
输出：2
示例 3：
输入：[5,1,5,2,5,3,5,4]
输出：5
提示：
    4 <= A.length <= 10000
    0 <= A[i] < 10000
    A.length 为偶数
*/

struct node_t
{
    int            key;    /* 数组元素          */
    int            value;  /* key 出现的次数    */
    struct node_t* left;   /* 左孩子结点        */
    struct node_t* right;  /* 右孩子结点        */
};

struct node_t* root     = NULL;
int*           temp_ptr = NULL;

void node_init(struct node_t* node_s, int key)
{
    if(node_s !=NULL)
    {
        node_s -> key   = key   ;
        node_s -> value = 1     ;
        node_s -> left  = NULL  ;
        node_s -> right = NULL  ;
    }
}

struct node_t* bst_insert(struct node_t* node_s, int key )
{
    if(node_s == NULL)
    {
        node_s = (struct node_t*)malloc(sizeof(struct node_t));
        node_init(node_s,key);
        return node_s;
    }
    
    if(key == node_s->key)
    {
        (node_s->value)++;
        temp_ptr = &(node_s->key);  /* 已经找到, 中断插入 */
        return node_s;
    }
    else if(key < node_s->key)
    {
        node_s->left = bst_insert(node_s->left, key );
    }
    else // key > node_s->key
    {
        node_s->right = bst_insert(node_s->right, key );
    }
    return node_s;
}

/* 可以省略 */
int* bst_dfs( struct node_t* node_s , int value)
{
    int* ret_val_left  = NULL;
    int* ret_val_right = NULL;
    if(node_s == NULL)
    {
        return NULL;
    }
    if(node_s->value == value)
    {
        return &(node_s->key);
    }
    else
    {
        ret_val_left  = bst_dfs(node_s->left,value);
        ret_val_right = bst_dfs(node_s->right,value);
        if(ret_val_left!=NULL)
        {
            return ret_val_left;
        }
        else
        {
            return ret_val_right;
        }
    }
    
    return NULL;
}

void bst_delete(struct node_t* bd_node_s)
{
    if(bd_node_s == NULL)
    {
        return;
    }
    
    if(bd_node_s->left != NULL)
    {
        bst_delete(bd_node_s->left);
        bd_node_s->left = NULL;
    }
    if(bd_node_s->right !=NULL)
    {
        bst_delete(bd_node_s->right);
        bd_node_s->right = NULL;
    }
    
    free(bd_node_s);
    bd_node_s = NULL;
    
    return ;
}

int repeatedNTimes(int* A, int ASize)
{
    int ret_val = 0;
    for(int i = 0; i < ASize ; i++)
    {
        root = bst_insert(root, A[i]);
        if(temp_ptr!=NULL)
        {
            break;
        }
    }
    ret_val = *temp_ptr;
    bst_delete(root);
    root     = NULL;
    temp_ptr = NULL;
    return ret_val;
}

/*
执行用时 : 40 ms, 在N-Repeated Element in Size 2N Array的C提交中击败了56.23% 的用户
内存消耗 : 8.7 MB, 在N-Repeated Element in Size 2N Array的C提交中击败了77.14% 的用户
102 / 102 个通过测试用例
状态：通过
执行用时：40 ms
*/