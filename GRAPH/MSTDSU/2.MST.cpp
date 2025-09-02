/*
##spanning Tree=>
Given an undirected and connected graph 
, a spanning tree of the graph 
 is a tree that spans 
 (that is, it includes every vertex of G) and is a subgraph of G 
 (every edge in the tree belongs to G)

 ##Minimum spanning tree=> The spanning Tree where the cost is minimum amoung all the spanning Trees.
*/
//----------------------------PRIM's ALGORITHM--------------------------
//preparation:minheap, visited array, mst array(optional) which stores mst edges
//minheap stores {wt,node}
//O((V+E)logV) because each edge is inserted in the priority queue only once and insertion in priority queue take logarithmic time.
int spanningTree(int V, vector<vector<int>> adj[])
	{
		priority_queue<pair<int, int>,
		               vector<pair<int, int> >, greater<pair<int, int>>> pq;

		vector<int> vis(V, 0);
		// {wt, node}
		pq.push({0, 0});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			// add it to the mst
			vis[node] = 1;
			sum += wt;
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return sum;
	}

//kruskal's algorithm
/*
INtution->1) sort the edges by their weight
		  2) use concept of disjoint set to join verices
*/
  int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
//Overall Time Complexity: (O(Elog E)) or (O(Elog V))
