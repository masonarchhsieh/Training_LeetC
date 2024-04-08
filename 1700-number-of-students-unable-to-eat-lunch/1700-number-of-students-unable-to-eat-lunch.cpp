class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt = 0;
        
        while (!students.empty() && !sandwiches.empty() && cnt < students.size()) {
            if (students.front() == sandwiches.front()) {
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                cnt = 0;
                continue;
            }
            
            // students.front() != sandwiches.front()
            students.push_back(students.front());
            students.erase(students.begin());
            cnt++;
        }

        return students.size();
    }
};