int trailingZeroes(int n)
{
    int ret_num = 0;
    do 
    {
        while(n>4)
        {
            ret_num += n / 5;
            n /=5
        }
    }while(0);
    return ret_num;
}

/*
执行用时 :0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗 :6.9 MB, 在所有 C 提交中击败了64.08%的用户
*/

