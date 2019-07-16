

int firstUniqChar(char * s){
    
    int char_num[26]    = {0,};
    int i               = 0;
    int ret_val         = -1;
    
    memset(char_num,0,sizeof(int)*26);
    
    /*第一次遍历,$O(N)$*/
    while(s[i])
    {
        ++char_num[s[i]-'a'];
        ++i;
    }
    
    /*第二次遍历$O(N)$*/
    i = 0;
    while(s[i])
    {
        if(char_num[s[i]-'a']==1)
        {
            ret_val = i;
            break;
        }
        ++i;
    }
    return ret_val;
}


/*
执行结果：通过
显示详情
执行用时 :16 ms, 在所有 C 提交中击败了84.11%的用户
内存消耗 :8.1 MB, 在所有 C 提交中击败了94.98%的用户
*/

