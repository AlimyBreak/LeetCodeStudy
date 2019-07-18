

int C_n_i(int n , int i )
{
    int ret_val = 1;
    int j = 1;
    
    while(j<=n)
    {
        ret_val *= j;
        j++;
    }
    j = 1;
    while(j <=i)
    {
        ret_val /= j;
        j++;
    }
    
    j = 1;
    while(j <=(n-i))
    {
        ret_val /= j;
    }
    return ret_val;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCasePermutation(char * S, int* returnSize)
{
    
    int     str_len     = str(S)                                ;
    char*   mark        = (char*)malloc(str_len*sizeof(char))   ;
    char*   en_ind      = (char*)malloc(str_len*sizeof(char))   ;
    int     num_en      = 0                                     ;
    int     i           = 0                                     ;
    char**  ret_val     = NULL                                  ;
    int     _returnSize = 0                                     ;
    char*   temp        = NULL                                  ;
    int     pailie      = 0                                     ;
    
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
        else
        {
            mark[i]  = 3;
        }
    }
    
    _returnSize = pow(2,num_en);
    ret_val = (char**)malloc(sizeof(char*)*_returnSize);
    for(i = 0; i < num_en;i++)
    {
        pailie = C_n_i(num_en,i);
        for(j=0;j<pailie;j++)
        {
            /*怎么写排列*/
        }
        
       
    }
    
    
    * returnSize = _returnSize;
    
    return ret_val;
    
}




char**  ret_val     = NULL      ;
int     num_en      = 0         ;
int     _returnSize = 0         ;
int     __count     = 0         ;

void __recusive(char * S,char*   mark)
{
    
}

char ** letterCasePermutation(char * S, int* returnSize)
{
    int     str_len     = str(S)                                ;
    char*   mark        = (char*)malloc(str_len*sizeof(char))   ;
    
    ret_val     = NULL      ;
    num_en      = 0         ;
    _returnSize = 0         ;
    __count     = 0         ;

    
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
        else
        {
            mark[i]  = 3;
        }
    }
    
    _returnSize = pow(2,num_en);
    ret_val = (char**)malloc(sizeof(char*)*_returnSize);
    
}
