class Solution
{
 

    /*大顶堆*/
    struct cmp
    {
        template<typename T, typename U>
            bool operator()(T const& left, U const& right)
            {
                if (left.second < right.second)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
    };


    public:
        string frequencySort(string s)
        {
            map<char,int>   mii                 ;
            int             i       =   0       ;
            string          ret_val             ;
            char            ch      =   0       ;
            int             fre     =   0       ;
            
            /*统计各字符串出现频次*/
            for(i = 0; i < s.size() ; i++)
            {
                if(mii.count(s[i]))
                {
                    mii[s[i]]++;
                }
                else
                {
                    mii[s[i]] = 1;
                }
            }
            
            priority_queue<pair<char,int>,vector<pair<char,int>>,cmp>  pq(mii.begin(),mii.end());
            pair<char,int> pci;
            while(!pq.empty())
            {
                pci = pq.top();
                ret_val += string(pci.second,pci.first);
                pq.pop();
            }
            
            return ret_val;
            
        }
};

/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 cpp 提交中击败了88.90% 的用户
内存消耗 :11.2 MB, 在所有 cpp 提交中击败了25.16%的用户
*/