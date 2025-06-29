class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        // Build graph and indegree array
        for (auto& e : prerequisites) {
            adj[e[1]].push_back(e[0]);
            indeg[e[0]]++;
        }

        queue<int> q;

        // Add all nodes with indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        int count = 0;

        // Kahn's algorithm
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[curr]) {
                indeg[neighbor]--;
                if (indeg[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If we were able to take all courses, return true
        return count == numCourses;
    }
};
