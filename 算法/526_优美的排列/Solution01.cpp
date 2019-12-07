class Solution
{
    
    private:
    
    
        void helper (   int&            ret_num     ,
                        int             N           ,
                        vector<bool>&   vb          ,
                        int             cur_level   
                    )
        {
            if(cur_level > N)
            {
                ret_num++;
                return;
            }

            for(int i = 1; i <= N ; i++)
            {
                if(vb[i]==true)
                {
                    continue;
                }
                else
                {
                    
                    if(i%cur_level==0 || cur_level%i==0)
                    {
                        vb[i] = true;
                        helper(ret_num,N,vb,cur_level+1);
                        vb[i] = false;
                    }   
                }
            }
            
        }
    
    public:
        int countArrangement(int N)
        {
            if(N<1)
            {
                return 0;
            }
            
            vector<bool>  vb(N+1,false);
            int ret_num = 0;
            
            helper(ret_num,N,vb,1);
            return ret_num;
            
        
        }
};

/*
执行结果：
通过
显示详情
执行用时 :256 ms, 在所有 cpp 提交中击败了43.78% 的用户
内存消耗 :8.2 MB, 在所有 cpp 提交中击败了72.22%的用户
*/