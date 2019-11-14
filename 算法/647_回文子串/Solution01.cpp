class Solution
{
    /* [ left , right ]*/
    private:
        bool isloopstr(string& s , int left , int right)
        {
            bool ret_val = true;
            while(left < right)
            {
                if(s[left] == s[right])
                {
                    left++;
                    right--;
                }
                else
                {
                    ret_val = false;
                    break;
                }
            }
            return ret_val; 
        }
        
    public:
        int countSubstrings(string s)
        {
            int ret_val =   0           ;
            int length  =   s.size()    ;
            int i       =   0           ;
            int j       =   0           ;
            int left    =   0           ;
            int right   =   0           ;
            
            ret_val += length;/*长度为1的都是回文串*/
            for(i = 1; i < length ; i ++)
            {
                for(j = 0 ; j < length - i ; j ++)
                {
                    if(isloopstr(s,j,j+i))
                    {
                        ret_val++;
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
执行用时 :320 ms, 在所有 cpp 提交中击败了12.40% 的用户
内存消耗 :8.4 MB, 在所有 cpp 提交中击败了93.86%的用户
*/