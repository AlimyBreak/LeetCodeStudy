

/*
统计所有小于非负整数 n 的质数的数量。
示例:
输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/


bool isPrime(int k)
{
    bool ret_val = false;
    do
    {
        if(k<=1)
        {
            ret_val = false;
            break;
        }
        
        if(   (k==2)
            ||(k==3)
        )
        {
            ret_val = true;
            break;
        }
        
        ret_val = true;
        for(i=3;i<k;i+2) /*能运行到这的k必定不是偶数,不包含2这个质因数*/
        {
            if(k%i == 0)
            {
                ret_val = false;
                break;
            }
        }
        
    }while(0);
    return ret_val;    
}

/*方法1:遍历法*/
int countPrimes(int n)
{
    int num = 0;
    int i   = 0;
    do
    {
        if(n <= 1)
        {
            break;
        }
        for(i = 2; i < n ; )
        {
            if(isPrime(i))
            {
                num++;
            }
            if(i==2)
            {
                i++;
            }
            else
            {
                i = i + 2;
            }
        }
        break;
    }while(0);
    return num;
}

/*
17 / 20 个通过测试用例
状态：超出时间限制
提交时间:1 分钟之前
最后执行的输入:
499979
*/

const int prime_arr[] = {
    
    //没完成该方法
    
};


/*找到第一个大于或等于k的数值的索引*/
int getNearestIndex( int k )
{
    int nearest_index = -1                      ;
    int left          = 0                       ;
    int right         = sizeof(prime_arr) - 1   ;
    int mid           = 0                       ;

    do
    {
        if( k <= prime_arr[left]    )
        {
            break;
        }
        
        if( k >= prime_arr[right]   )
        {
            nearest_index = right + 1;
            break;
        }
        
        while(left<right)
        {
            mid = (left + right)/2;
            
            if(prime_arr[mid]==k)
            {
                nearest_index = mid;
                break;
            }
            else if(prime_arr[mid]<k)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        
        if(nearest_index!=-1)
        {
            break;
        }
        else
        {
            nearest_index = (left+right)/2;
            if(prime_arr[nearest_index]<k)
            {
                while(prime_arr[nearest_index++]<k);
            }
            else if(prime_arr[nearest_index]>k)
            {
                while(prime_arr[nearest_index--]>k);
                nearest_index++;
            }
        }
    }

    return nearest_index;
}


/*二分查表法*/
int countPrimes(int n )
{
    int nearest_index   = 0;
    int ret_val         = 0;
    
    nearest_index = getNearestIndex(n);
    
    if(nearest_index == -1)
    {
        ret_val = 0;
    }
    else
    {
        if(prime_arr[nearest_index] == k)
        {
            ret_val =   nearest_index;
        }
        else
        {
            ret_val =   nearest_index + 1;
        }   
    }
    return ret_val;
}

