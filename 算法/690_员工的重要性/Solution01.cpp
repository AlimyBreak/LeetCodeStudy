/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution
{
    
    private:
    
        int __getImportance(vector<Employee*>& employees, int id)
        {
            int size1 = employees.size();
            int ret_val = 0;
            for(int i = 0 ; i < size1 ; i++)
            {
                if(id == employees[i]->id)
                {
                    ret_val += employees[i]->importance;
                    int size2 = employees[i]->subordinates.size();
                    for(int j = 0 ; j < size2 ; j++ )
                    {
                        ret_val += __getImportance(employees,employees[i]->subordinates[j]);
                    }
                    break;
                }
                
            }
            return ret_val;
        }
    
    public:
        int getImportance(vector<Employee*> employees, int id)
        {
            return __getImportance(employees,id);
        }
};



/*
执行结果：
通过
显示详情
执行用时 :56 ms, 在所有 C++ 提交中击败了25.43% 的用户
内存消耗 :14.1 MB, 在所有 C++ 提交中击败了96.56%的用户
*/