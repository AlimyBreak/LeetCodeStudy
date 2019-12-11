class Solution
{
    public:
        vector<int> grayCode(int n)
        {   
            if(n == 0)
            {
                return {0};
            }
            vector<int> vi  =   grayCode(n-1)   ;
            int         i   =   0               ;
            /*n层共有 2^n 个格雷码, 前(n-1)层共有 2^(n-1)个格雷码*/
            for( i = pow(2,n-1)-1; i >= 0 ; i--)
            {
                vi.push_back(vi[i] | (0x01 << (n-1)));
            }
            return vi;
    }
};
/*
执行结果：
通过
显示详情
执行用时 :12 ms, 在所有 cpp 提交中击败了18.56% 的用户
内存消耗 :8.7 MB, 在所有 cpp 提交中击败了20.23%的用户
*/