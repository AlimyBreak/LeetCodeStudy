class Solution
{
    private:
        int     arr[9]  = {1,2,6,24,120,720,5040,40320,362880}  ;
        //                 1 2 3 4   5   6  7    8     9
        
        void helper (   string&     s,
                        int         n,
                        int         k
                    )
        {
            
            if( k < 1 || k > arr[n-1])
            {
                return ; /* k值越界*/
            }

            
        }
    
    
    public:
        string getPermutation(  int     n   ,
                                int     k
                             )
        {
            string  s ;
            helper(s,n,k);
            return s.;
        }
};



/*
90 / 200 个通过测试用例
	状态：超出时间限制
	
提交时间：3 分钟之前
最后执行的输入： 9
199269

*/