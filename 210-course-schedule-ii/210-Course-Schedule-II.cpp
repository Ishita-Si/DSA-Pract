class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course); 
            indegree[course]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

       vector<int> answer;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            answer.push_back(node);
            
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        if (answer.size() != numCourses) {
            return {};
        }
        
        return answer;
    }
};