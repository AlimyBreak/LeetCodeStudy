class Solution
{

    public:
        vector<int> grayCode(int n)
        {
            
            int         i           =   0           ;
            int         sum_count   =   pow(2,n)    ;
            int         cur_count   =   0           ;

            if(n < 0)
            {
                return vector<int>();
            }

            vector<int> vi(sum_count,0);
            for(i = 0 ; i < sum_count;i++)
            {
                vi[i] = i ^ (i>>1);
            }


            return vi;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 cpp 提交中击败了97.72% 的用户
内存消耗 :8.8 MB, 在所有 cpp 提交中击败了13.41%的用户
*/