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
    private:
        vector<int> ret_val;
        
    
        void __PreOrder(Node* node)
        {
            int size = 0;
            int i    = 0;
            if(node==NULL)
            {
                return;
            }
            else
            {
                ret_val.push_back(node->val);
                size = node->children.size();
                for(i=0;i<size;i++)
                {
                    __PreOrder(node->children[i]);
                }
            }
        }
    public:
        vector<int> preorder(Node* root)
        {
            ret_val.clear();
            __PreOrder(root);
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :368 ms, 在所有 C++ 提交中击败了18.87% 的用户
内存消耗 :32.7 MB, 在所有 C++ 提交中击败了84.08%的用户
*/