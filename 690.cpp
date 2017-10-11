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
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> hashmap;
        queue<int> q;
        int res = 0;
        
        for (Employee* ptr : employees)
            hashmap[ptr->id] = ptr;
        
        q.push(id);
        while (!q.empty()) {
            Employee* cur = hashmap[q.front()];
            q.pop();
            
            res += cur->importance;
            for (int child : cur->subordinates)
                q.push(child);
        }
        return res;
    }
};
