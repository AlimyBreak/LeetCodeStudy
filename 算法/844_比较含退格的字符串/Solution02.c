typedef struct tag_nanmian_stack
{
    char arr[200];
    int  length;
}nanman_stack_t;



/*初始化栈结构体*/
void stack_init(nanman_stack_t* nanman_stack_s)
{
    nanman_stack_s->length = 0;
}

/*向栈内压入一个字符*/
void stack_push(nanman_stack_t* nanman_stack_s,char ch)
{
    nanman_stack_s->arr[nanman_stack_s->length] = ch;
    (nanman_stack_s->length)++;
}

/*出栈一个字符*/
void stack_pop(nanman_stack_t* nanman_stack_s)
{
    if(nanman_stack_s->length>0)
    {
        (nanman_stack_s->length)--;
    }
}

/*判断栈的内容是否一样*/
bool stack_isequal( nanman_stack_t* nanman_stack_s1 ,
                    nanman_stack_t* nanman_stack_s2
                  )
{
    bool ret_val    =   true    ;
    int  i          =   0       ;
    do{
        if(nanman_stack_s1->length != nanman_stack_s2->length)
        {
            ret_val = false;
            break;
        }
        
        for(i=0;i<nanman_stack_s1->length;i++)
        {
            if(nanman_stack_s1->arr[i]!=nanman_stack_s2->arr[i])
            {
                ret_val = false;
                break;
            }
        }
    }while(0);
    
    return ret_val;
}


bool backspaceCompare(char* S, char* T)
{
    nanman_stack_t nanman_stack_S;
    nanman_stack_t nanman_stack_T;
    int i = 0;
    
    stack_init(&nanman_stack_S);
    stack_init(&nanman_stack_T);
    while(S[i])
    {
        if(S[i]=='#')
        {
            stack_pop(&nanman_stack_S);
        }
        else
        {
            stack_push(&nanman_stack_S,S[i]);
        }
        i++;
    }
    
    i = 0;
    while(T[i])
    {
        if(T[i]=='#')
        {
            stack_pop(&nanman_stack_T);
        }
        else
        {
           stack_push(&nanman_stack_T,T[i]);
        }
        i++;
    }
    return stack_isequal(&nanman_stack_S,&nanman_stack_T);
}

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了81.54%的用户
内存消耗 :6.7 MB, 在所有 C 提交中击败了89.47%的用户
*/
