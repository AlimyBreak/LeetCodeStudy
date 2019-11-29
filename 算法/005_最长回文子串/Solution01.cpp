class Solution
{
    
    private:
    
        void helper(    string& ret_val ,
                        string& s       ,
                        int     left    ,
                        int     right
        )
        {
            if(left < 0 || right >= s.size())
            {
                return;
            }

            if(s[left]!=s[right])
            {
                return;
            }
            else
            {
                if(ret_val.size()<right-left+1)
                {
                    ret_val = s.substr(left,right-left+1);
                }
                helper(ret_val,s,left-1,right+1);
            }
        }
        
    public:
        string longestPalindrome(string s)
        {
            string ret_val;
            
            if(s.size()<=1)
            {
                return s;
            }
            ret_val = s.substr(0,1); /*至少有一个长度*/
            for(int i = 0 ; i < s.size() ; i++)
            {
                /*偶数回文*/
                helper(ret_val,s,i,i+1);
                /*奇数回文*/
                helper(ret_val,s,i-1,i+1);
            }
            
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :144 ms, 在所有 cpp 提交中击败了45.31% 的用户
内存消耗 :14 MB, 在所有 cpp 提交中击败了43.98%的用户
*/