
char ** letterCasePermutation(char * S, int* returnSize)
{
    
    int     str_len         =   strlen(S)                               ;
    char*   mark            =   (char*)malloc(str_len*sizeof(char))     ;
    char*   en_ind          =   (char*)malloc(str_len*sizeof(char))     ;
    int     num_en          =   0                                       ;
    int     i               =   0                                       ;
    char**  ret_val         =   NULL                                    ;
    int     __returnSize    =   0                                       ;
    char*   temp            =   NULL                                    ;
    int     j               =   0                                       ;
    int     arr[12]         =   {   0x0001,0x0002,0x0004,0x0008,
                                    0x0010,0x0020,0x0040,0x0080,
                                    0x0100,0x0200,0x0400,0x0800
                                };
                                
    /*先遍历一遍,获取字符个数和他们出现的位置,O(n)*/
    for(i = 0; i < str_len ; i++)
    {
        if((S[i] >='A') && (S[i]<='Z'))
        {
            mark[num_en]        = 1;    /*标记为大写字母*/
            en_ind[num_en++]    = i;    
        }
        else if((S[i] >='a') && (S[i]<='z'))
        {
            mark[num_en]        = 2;    /*标记为小写字母*/       
            en_ind[num_en++]    = i;
        }
    }
    
    /*计算排列个数及每种排列情况*/
    __returnSize = pow(2,num_en);    /*有2的n次方种可能*/
    ret_val = (char**)malloc(sizeof(char*)*__returnSize);
    for(i = 0; i < __returnSize;i++)
    {
        temp            =   (char*)malloc((str_len+1)*sizeof(char)) ;/*多申请一字节作为字符串结束标记*/
        temp[str_len]   =   0                                       ;
        memcpy(temp,S,str_len*sizeof(char))                         ;/*先拷贝过来*/
        for( j = 0 ; j < num_en ; j++ )
        {
            if(i&arr[j])    // 0x01 << j
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
    
    /*回收动态资源*/
    free(mark);
    mark = NULL;
    free(en_ind);
    mark = NULL;
    /*返回处理*/
    *returnSize = __returnSize;
    return ret_val;
}

/*
执行结果：通过
显示详情
执行用时 :24 ms, 在所有 C 提交中击败了26.67%的用户
内存消耗 :9.9 MB, 在所有 C 提交中击败了90.91%的用户
*/
