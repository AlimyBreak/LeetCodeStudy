class Solution
{

    public:
        int lastStoneWeight(vector<int>& stones) 
        {
            priority_queue<int> pqi;
            int maxdata1 = 0;
            int maxdata2 = 0;
            int i        = 0;

            for(i = 0;i<stones.size();i++)
            {
                pqi.push(stones[i]);
            }

            while (pqi.size() > 1)
            {
                maxdata1 = pqi.top();
                pqi.pop();
                maxdata2 = pqi.top();
                pqi.pop();
                if(maxdata1!=maxdata2)
                {
                    pqi.push(maxdata1-maxdata2);
                }
            }

            if(pqi.size() ==0)
            {
                return 0;
            }
            else
            {
                return pqi[0];
            }
        }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了84.90% 的用户
内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户
*/