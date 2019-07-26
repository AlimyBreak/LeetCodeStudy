
bool isVowel(char c)
{
    bool ret_val = false;
    ret_val = (c == 'a') || ( c == 'o') || (c == 'e') || ( c == 'i') || (c == 'u') || (c == 'A') || ( c == 'O') || (c == 'E') || ( c == 'I') || (c == 'U')  ;
    return ret_val;
}


char* reverseVowels(char* s)
{
    int     len     =   strlen(s)   ;
    char    temp    =   0           ;/*用于数据交换*/
    int     left    =   0           ;
    int     right   =   len-1       ;
    
    while(left<right)
    {
        if(isVowel(s[left])==false)
        {
            left++;
            continue;
        }
        
        if(isVowel(s[right])==false)
        {
            right--;
            continue;
        }

        temp        =   s[left]     ;
        s[left]     =   s[right]    ;
        s[right]    =   temp        ;
        left++  ;
        right-- ;        
    }
    return s;
}


/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了97.22% 的用户
内存消耗 :7.9 MB, 在所有 C 提交中击败了5.36%的用户
*/