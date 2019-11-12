class Solution
{
    public:
        string originalDigits(string s)
        {
            int     charCount[10]   = {0,}  ;  /* z o w t r v x s g i*/
            int     i               = 0     ;
            string  ret_val                 ;
            
            for(i = 0 ; i < s.size();i++)
            {
                switch(s[i])
                {
                    case 'z':
                        charCount[0]++;
                    break;
                    case 'o':
                        charCount[1]++;
                    break;
                    case 'w':
                        charCount[2]++;
                    break;
                    case 't':
                        charCount[3]++;
                    break;
                    case 'r':
                        charCount[4]++;
                    break;
                    case 'v':
                        charCount[5]++;
                    break;
                    case 'x':
                        charCount[6]++;
                    break;
                    case 's':
                        charCount[7]++;
                    break;
                    case 'g':
                        charCount[8]++;
                    break;
                    case 'i':
                        charCount[9]++;
                    break;
                }
            }
            
            charCount[3]    =   charCount[3] - charCount[2] - charCount[8]                  ;
            charCount[4]    =   charCount[4] - charCount[3] - charCount[0]                  ;
            charCount[7]    =   charCount[7] - charCount[6]                                 ;
            charCount[1]    =   charCount[1] - charCount[4] - charCount[2] - charCount[0]   ;
            charCount[5]    =   charCount[5] - charCount[7]                                 ;
            charCount[9]    =   charCount[9] - charCount[8] - charCount[6] - charCount[5]   ;
            
            
            for(i = 0 ; i < 10;i++)
            {
                if(charCount[i])
                {
                    ret_val += string(charCount[i],(char)(i+'0'));
                }
            }
            
            return ret_val;
            
        
        }
};

/*
执行结果：
通过
显示详情
执行用时 :24 ms, 在所有 cpp 提交中击败了77.94% 的用户
内存消耗 :11.8 MB, 在所有 cpp 提交中击败了25.64%的用户
*/