class Solution
{
    public:
        vector<vector<int>> generate(int numRows)
        {
            vector<vector<int>>     ret_val         ;
            vector<int>             vi              ;
            int                     i       = 0     ;
            int                     j       = 0     ;
            if(numRows<=0)
            {
                return ret_val;
            }
            else
            {
                for(i = 0; i < numRows ; i++ )
                {
                    vi.clear();
                    do
                    {
                        vi.push_back(1);    /*头*/
                        if(i==0)
                        {
                            break;
                        }
                        for(j = 0; j <i-1;j++)
                        {
                            vi.push_back(ret_val[i-1][j]+ret_val[i-1][j+1]);
                        }
                        vi.push_back(1);    /*尾*/
                    }while(0);
                    ret_val.push_back(vi);
                }
                return ret_val;
            }
        }
};


/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了40.12%的用户
*/
