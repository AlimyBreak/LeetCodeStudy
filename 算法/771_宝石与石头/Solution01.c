
int countChar(char*S , char ch)
{
    int ret_val =   0;
    int i       =   0;
    while(S[i])
    {
        if(S[i]==ch)
        {
            ret_val++;
        }
        i++;
    }

    return ret_val;
}


int numJewelsInStones(  char*   J   ,
                        char*   S
                    )
{
    int ret_val = 0;
    int i = 0;
    while (J[i])
    {
        ret_val += countChar(S,J[i]);
        i++;
    }
    return ret_val;
}


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C 提交中击败了21.55% 的用户
内存消耗 :6.6 MB, 在所有 C 提交中击败了91.34%的用户
*/