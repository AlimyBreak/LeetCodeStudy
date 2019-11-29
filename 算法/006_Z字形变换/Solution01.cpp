class Solution
{
    public:
        string convert(string s, int numRows)
        {
            if(numRows<=1)
            {
                return s;
            }
            
            string  ret_val(s)      ;
            int     ret_num     = 0 ;
            int     i           = 0 ;
            int     count       = 0 ;/*0-偶数次 1-奇数次*/
            int     temp        = 0 ;
            // 第0行
            temp = 0;
            while(temp < s.size())
            {
                ret_val[ret_num++] = s[temp];
                temp += 2*(numRows-1);
            }
            // 第1--> numRows-2 行
            for(i = 1 ; i < numRows-1;i++)
            {
                temp    =   i   ;
                count   =   0   ;
                while(temp < s.size())
                {
                    ret_val[ret_num++] = s[temp];
                    if(count==0)
                    {
                        temp += 2*(numRows-i-1);
                        count = 1;
                    }
                    else
                    {
                        temp += 2*i;
                        count = 0;
                    }
                }
            }
            // 第numRows-1行
            temp = numRows-1;
            while(temp < s.size())
            {
                ret_val[ret_num++] = s[temp];
                temp += 2*(numRows-1);
            }
            
            return ret_val;
        
        }
};

/*
执行结果：
通过
显示详情
执行用时 :20 ms, 在所有 cpp 提交中击败了51.28% 的用户
内存消耗 :10 MB, 在所有 cpp 提交中击败了97.22%的用户
*/