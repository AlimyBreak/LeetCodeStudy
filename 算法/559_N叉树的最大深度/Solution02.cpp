/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
    
    int __dfs(Node* node,int cur_level)
    {
        vector<int> vi;
        int size    =   0;
        int i       =   0;
        int temp    =   0;
        
        if(node==NULL)
        {
            return cur_level;
        }
        
        size = node->children.size();
        if(size==0)
        {
            return (cur_level+1);
        }
        else
        {
            for(i = 0;i<size;i++)
            {
                vi.push_back(__dfs(node->children[i],cur_level+1));
            }
            temp = vi[0];
            for(i = 1;i<size;i++)
            {
                if(vi[i]>temp)
                {
                    temp = vi[i];
                }
            }
            return temp;
        }
    }
public:
    int maxDepth(Node* root)
    {
        int             ret_val =   0       ;
        int             num_1   =   0       ;
        int             num_2   =   0       ;
        int             i       =   0       ;   
        int             j       =   0       ;
        Node*           temp    =   NULL    ;
        queue<Node*>    qu                  ;
        
        do
        {
            if(root==NULL)
            {
                break;
            }
            ret_val = __dfs(root,0);
        }while(0);
        return ret_val;
    }
};


/*
执行结果：
通过
显示详情
执行用时 :300 ms, 在所有 C++ 提交中击败了37.84% 的用户
内存消耗 :33.2 MB, 在所有 C++ 提交中击败了5.04%的用户
*/

