class Solution
{
    public:
        int lastStoneWeight(vector<int>& stones) 
        {
            if(stones.size()==1)
            {
                return stones[0];
            }
            else if(stones.size()<=0)
            {
                return 0;
            }
            else
            {
                while (1)
                {
                    sort(stones.begin(),stones.end(),greater<int>());
                    if(stones[1]==0)
                    {
                        return stones[0];
                    }
                    else
                    {
                        stones[0] = stones[0]-stones[1];
                        stones[1] = 0;
                    }
                }
            }
        }
};

/*
?????
??
????
???? :4 ms, ??? C++ ??????84.90% ???
???? :8.3 MB, ??? C++ ??????100.00%???
*/