

/*
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
示例 1：
输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]
示例 2：
输入：["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
*/


void reverse_char_array(char* s,int left ,int right)
{
    int     swap_times  =   (right - left + 1)/2;
    char    temp        =   0;
    int     i           =   0;
    for( i = 0; i < swap_times ; i++)
    {
        temp       = s[left+i];
        s[left+i]  = s[right-i]; 
        s[right-i] = temp;
    } 
}

void reverseString(char* s, int sSize)
{
    reverse_char_array(s,0,sSize-1);
}

/*
感动: 
执行用时 : 64 ms, 在Reverse String的C提交中击败了98.94% 的用户 
内存消耗 : 13.5 MB, 在Reverse String的C提交中击败了75.79% 的用户
478 / 478 个通过测试用例
状态：通过
执行用时：68 ms	
提交时间：5 分钟之前
*/