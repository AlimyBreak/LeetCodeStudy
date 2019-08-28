int numJewelsInStones(char* J, char * S)
{
    short int count_ch[128] = {0,};
    int i                   = 0;
    int ret_val             = 0;
    //memset(count_ch,0,sizeof(count_ch));
    while (S[i])
    {
        count_ch[S[i]] ++;
        i++;
    }
    i = 0;
    while (J[i])
    {
        ret_val += count_ch[J[i]];
        i++;
    }
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了71.55% 的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了80.74%的用户
*/