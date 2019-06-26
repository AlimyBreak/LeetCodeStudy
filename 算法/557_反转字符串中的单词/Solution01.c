/*
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
*/


/* s[head~tail] reverse */
void reverseSubstr(char* s , int head, int tail)
{
    char temp = 0;
    while(head < tail)
    {
        temp    = s[tail]   ;
        s[tail] = s[head]   ;
        s[head] = temp      ;
        head++  ;
        tail--  ;
    }
}

char* reverseWords(char * s)
{
    
    int head = 0    ;
    int tail = -2   ;
    int i    = 0    ;
    
    while((s[i]!='\0'))
    {
        if(s[i]==' ')
        {
            head = tail + 2             ;
            tail = i-1                  ;
            reverseSubstr(s,head,tail)  ;
        }
        i++;
    }
    
    if(  ( i >1        )
       &&( s[i-1]!=' ' )
    )
    {
        head = tail+2                   ;
        tail = i-1                      ;
        reverseSubstr(s,head,tail)      ;
    }
    return s;
}

/*
执行用时 :12 ms, 在所有 C 提交中击败了92.24%的用户
内存消耗 :8.3 MB, 在所有 C 提交中击败了45.10%的用户
*/
