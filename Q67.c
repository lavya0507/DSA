#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topologicalSort(int V, vector<int> adj[]) {
        vector<int> inDegree(V, 0);
        vector<int> result;
        queue<int> q;

        // 1. Calculate in-degree for every vertex
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                inDegree[neighbor]++;
            }
        }

        // 2. Push all vertices with 0 in-degree into the queue
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // 3. Process the queue
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            // For every neighbor, reduce its in-degree
            for (int v : adj[u]) {
                inDegree[v]--;
                // If in-degree becomes 0, add to queue
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // If result size < V, there's a cycle (not a DAG)
        if (result.size() != V) return {}; 

        return result;
    }
};
