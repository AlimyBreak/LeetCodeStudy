void __swap(int*a ,int*b)
{
    int c = *a;
    *a = *b;
    *b = c;
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


void selectionSort( int* arr ,int n )
{
    
    int maxIndex = 0;
    for( int i = 0 ; i < n ; i++)
    {
        // 寻找 [i,n)区间内的最大值
        maxIndex = i;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j] > arr[maxIndex]) // 
            {
                maxIndex = j;
            }
            // C++ 内置, 视C++标准支持情况,std 中就有或者 #include <algorithm>
            
        }
        __swap(&arr[i],&arr[maxIndex]);
    }
}


int largestPerimeter(int* A, int ASize)
{
    int ret_val = 0;
    int a       = 0;
    int b       = 0;
    int c       = 0;
    int i       = 0;
    /* 排序*/
    selectionSort(A,ASize);
    for(i=0;i<ASize-2;i++)
    {
        a = A[i];
        b = A[i+1];
        c = A[i+2];
        if(test(a,b,c))
        {
            ret_val = a + b + c;
            break;
        }   
    }
    return ret_val;
}



/*
选择排序超时了
*/