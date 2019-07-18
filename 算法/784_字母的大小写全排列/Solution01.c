char ** letterCasePermutation(char * S, int* returnSize)
{
    
    int     str_len     = strlen(S)                             ;
    char*   mark        = (char*)malloc(str_len*sizeof(char))   ;
    char*   en_ind      = (char*)malloc(str_len*sizeof(char))   ;
    int     num_en      = 0                                     ;
    int     i           = 0                                     ;
    char**  ret_val     = NULL                                  ;
    int     _returnSize = 0                                     ;
    char*   temp        = NULL                                  ;
    int     j = 0;
    for(i = 0; i < str_len ; i++)
    {
        if((S[i] >='A') && (S[i]<='Z'))
        {
            mark[i]  = 1;
            en_ind[num_en++] = i;
        }
        else if((S[i] >='a') && (S[i]<='z'))
        {
            mark[i]  = 2;
            en_ind[num_en++] = i;
        }
    }
    
    _returnSize = pow(2,num_en);
    ret_val = (char**)malloc(sizeof(char*)*_returnSize);
    for(i = 0; i < _returnSize;i++) /*0~2^n-1*/
    {
        temp = (char*)malloc((str_len+1)*sizeof(char));
        temp[str_len] = 0;
        memcpy(temp,S,str_len*sizeof(char));
        for(j=0;j<num_en;j++)
        {
            if(i&arr[j]) /*对应二进制为1就大小写之间互转*/
            {
                if(mark[en_ind[j]]==1) //原为大写字母
                {
                    temp[en_ind[j]] |= 0x20;
                }
                else
                {
                    temp[en_ind[j]] &= ~0x20; 
                }
            }
        }
        
        ret_val[i] = temp;

    }
    
    free(mark);
    mark = NULL;
    free(en_ind);
    en_ind = NULL;
    
    *returnSize = _returnSize;
    return ret_val;
}

/*
执行用时 :28 ms, 在所有 C 提交中击败了13.33%的用户
内存消耗 :9.9 MB, 在所有 C 提交中击败了90.91%的用户
*/
