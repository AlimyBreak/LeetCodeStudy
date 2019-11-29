class Solution
{
    
    private:
        void helper(    int&            ret_val     ,
                        int             cur_n       ,
                        int             cur_idx     ,
                        vector<int>&    visited
        )
        {
            if(cur_idx == cur_n)
            {
                ret_val++;
                return;
            }
            
            for( int i = 0 ; i < 10 ; i++)  /**/
            {
                if(  (visited[i] == 1)
                   ||(i == 0 && cur_idx == 0)// 去掉以0开头的
                )
                {
                    continue;
                }
                else
                {
                    visited[i] = 1;
                    helper(ret_val,cur_n,cur_idx+1,visited);
                    visited[i] = 0;
                }
            }
        }
        
    public:
        int countNumbersWithUniqueDigits(int n)
        {
            int ret_val = 0;
            
            if(n < 0)
            {
                return ret_val;
            }
            
            ret_val = 1;/* n = 0*/
            
            if(n > 10)
            {
                n = 10;
            }
            
            vector<int> visited(10,0);/*0~9*/
            for(int i = 1; i <= n ;i++)
            {
                helper(ret_val,i,0,visited);
            }

            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :92 ms, 在所有 cpp 提交中击败了10.08% 的用户
内存消耗 :8.3 MB, 在所有 cpp 提交中击败了13.51%的用户
*/