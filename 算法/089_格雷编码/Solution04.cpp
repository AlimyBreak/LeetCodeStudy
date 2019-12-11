class Solution
{
    
    private:
    
        void helper(    vector<int>&    vi  ,
                        int             n
        
        )
        {
            if(n==0)
            {
                vi.push_back(0);
                return;
            }
            helper(vi,n-1);
            
            /*n层共有 2^n 个格雷码, 前(n-1)层共有 2^(n-1)个格雷码*/
            for(int i = pow(2,n-1)-1; i >= 0 ; i--)
            {
                vi.push_back(vi[i] | (0x01 << (n-1)));
            }
        }
    
    
    public:
        vector<int> grayCode(int n)
        {   
        
        
            vector<int> vi;
            
            if(n > 0)
            {
                helper(vi,n);
            }
            return vi;
    }
};
/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 cpp 提交中击败了65.15% 的用户
内存消耗 :8.8 MB, 在所有 cpp 提交中击败了10.45%的用户
*/