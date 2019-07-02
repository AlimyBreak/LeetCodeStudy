/*
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
如果不存在最后一个单词，请返回 0 。
说明：一个单词是指由字母组成，但不包含任何空格的字符串。
示例:
输入: "Hello World"
输出: 5
*/

/* 常规方法:先忽略末尾空格再计数到字符串头或字符串中的空格*/
int lengthOfLastWord(char* s)
{
    int   str_len   = strlen(s)   ;
    int   ret_val   = 0           ;
    int   index     = str_len-1   ;
    
    do
    {
        /*忽略字符串末尾的空格*/
        while(  (   index    >= 0   )
              &&(   s[index] == ' ' )
        )
        {
            index--;
        }
        if(  (      index   <   0   )
           ||(      str_len ==  0   )
        )
        {
            ret_val = 0;
            break;
        }
        
        while(  ( index    >= 0     )
              &&( s[index] != ' '   )
        )
        {
            ret_val++;
            index--;
        }
        break;
    }while(0);
    
    return ret_val;
}


/*
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :7 MB, 在所有 C 提交中击败了81.05%的用户
*/

