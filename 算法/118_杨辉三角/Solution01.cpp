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
                for(i = 0; i < numRows ;i++)
                {
                    vi.clear();
                    do
                    {
                        if(i==0)
                        {
                            vi.push_back(1);
                            break;
                        }
                        if(i==1)
                        {
                            vi.push_back(1);
                            vi.push_back(1);
                            break;
                        }
                        vi.push_back(1);
                        for(j = 0; j <ret_val[i-1].size()-1;j++)
                        {
                            vi.push_back(ret_val[i-1][j]+ret_val[i-1][j+1]);
                        }
                        vi.push_back(1);
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
执行用时 :4 ms, 在所有 C++ 提交中击败了88.48%的用户
内存消耗 :8.6 MB, 在所有 C++ 提交中击败了76.88%的用户
*/