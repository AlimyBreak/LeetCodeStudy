class Solution
{
    
    public:
        vector<int> getRow(int rowIndex)
        {
            int             i       = 0 ;
            vector<int>     ret_val     ;
            unsigned long   temp    = 1 ;
            
            ret_val.push_back(1);
            for(i = 1; i <= rowIndex ; i++)
            {
                temp = temp * (rowIndex-i+1);
                temp = temp / i ;
                ret_val.push_back(temp);
            }
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8 MB, 在所有 C++ 提交中击败了99.84%的用户
*/