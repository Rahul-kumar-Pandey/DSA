/*
problem with Dijkstra's 
1) negative weight edge
2) negative cycle
*** yeh algo insab case me v kaam krta hai
*/
//ALGORITHM:
//do (v-1) iterations and relax edges( where v is no. of vertices)
//v th iteration will give info about negative cycle(HOW?)
                //we need only v-1 iteration to find shortest path for all vertices and vth iterations indicates existance of a cycle
//TC: O(v*e)

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
		vector<int> dist(V, 1e8);
		dist[S] = 0;
		for (int i = 0; i < V - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
		// Nth relaxation to check negative cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				return { -1};
			}
		}
		return dist;
	}
