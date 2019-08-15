
/*
    归并过程,对arr[left,right]的范围进行归并
*/
void __merge( int* arr, int left, int mid,int right)
{
    int     i   =   0                                           ;
    int     j   =   0                                           ;
    int     k   =   0                                           ;
    int*    aux =   (int*)malloc(sizeof(int)*(right-left+1))    ;
    
    /* 先拷贝出来 */
    for(i = left ; i<=right;i++)
    {
        aux[i-left] = arr[i];
    }

    /* 进行有序数组合成 */
    i = left;
    j = mid + 1;
    for(k=left;k<=right;k++)    /* 要存入位置的索引*/
    {
        if(i>mid)   /* 索引合法性*/
        {
            arr[k] = aux[j-left];
            j++;
        }
        else if(j > right) /* 索引合法性*/
        {
            arr[k] = aux[i-left];
            i++;
        }
        else if( aux[i-left] < aux[j-left]) /* 索引已经合法 */
        {
            arr[k] = aux[i-left];
            i++;
        }
        else
        {
            arr[k] = aux[j-left];
            j++;
        }
    }
    
    free(aux);
    return ;
}


/*
    递归使用归并排序,对arr[left,right]的范围进行排序
*/
void __mergeSort( int* arr, int left,int right) // 表征私有,不应该被外部调用,但可以被外部调用
{
    /* 递归到顶*/
    if(left>=right)
    {
        return ;
    }

    int mid = left + (right - left)/2;  // 防止溢出  
    __mergeSort(arr,left,mid);
    __mergeSort(arr,mid+1,right);
    
    /* 优化添加,针对已经有序的不需要重新归并排序*/
    if(arr[mid]<=arr[mid+1])
    {
        return ;
    }
    else
    {
        __merge(arr,left,mid,right); /* 两个有序数组归并过程*/
    }
}

bool test(int a,int b,int c)
{
    if(  (a<=0)
       ||(b<=0)
       ||(c<=0)
    )
    {
        return false;
    }
    else
    {
        if(a<(b+c))
        {
            return true;
        }
    }   
    return false;    
}


int largestPerimeter(int* A, int ASize)
{
    int ret_val = 0;
    int a       = 0;
    int b       = 0;
    int c       = 0;
    int i       = 0;

    /* 排序*/
    __mergeSort(A,0,ASize-1);
    
    /*逐一判决*/
    for(i=ASize-1;i>=2;i--)
    {
        a = A[i];
        b = A[i-1];
        c = A[i-2];
        if(test(a,b,c))
        {
            ret_val = a + b + c;
            break;
        }
    }
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :164 ms, 在所有 C 提交中击败了10.61% 的用户
内存消耗 :32.1 MB, 在所有 C 提交中击败了5.26%的用户
*/