class Solution
{
    public:
        string convert(string s, int numRows)
        {
            if(numRows<=1)
            {
                return s;
            }
            
            string  ret_val(s)                  ;
            int     ret_num                 = 0 ;
            int     i                       = 0 ;
            int     count                   = 0 ;/*0-偶数次 1-奇数次,2-顶层或者底层*/
            int     temp                    = 0 ;
            
            
            for(i = 0 ; i < numRows;i++)
            {
                temp  = i;
                count = 0;
                if(i == 0 || i == numRows-1)
                {
                    count = 2;
                }
                while(temp < s.size())
                {
                    ret_val[ret_num++] = s[temp];
                    if(count==0)
                    {
                        temp += 2*(numRows-i-1);
                        count = 1;
                    }
                    else if(count==1) 
                    {
                        temp += 2*i;
                        count = 0;
                    }
                    else
                    {
                        temp += 2*(numRows-1);
                    }
                }
            }
            return ret_val;
        
        }
};

/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 cpp 提交中击败了70.03% 的用户
内存消耗 :9.8 MB, 在所有 cpp 提交中击败了98.99%的用户
*/
