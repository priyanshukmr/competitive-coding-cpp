//DFS-based

int n; // vertices
vector<int> topo;
vec<int> adj[SZ];
int indexOf[SZ];

void dfs(int v) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u])
            dfs(u);
    }
    topo.push_back(v);
}

void topological_sort() {
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs(i);
    }
    reverse(all(topo));
}

bool isCyclic() {
	for(int i = 0; i < topo.size(); i++) 
	indexOf[topo[i]] = i;
	for(pii e: directed) {
		if(indexOf[e.fi] > indexOf[e.se])
		return true;
	}
	return false;
}




//BFS-based

/*      KAHN's ALGORITHM toposort using BFS.     */
// Problem: lexicographically smallest topological sort https://www.spoj.com/problems/TOPOSORT/
// detects cycle also (no toposort exists)

vector<int> kahns_algo(vector<int> &indegree) {
    vector<int> topo;
    set<int> minHeap;
    for(int i=1; i<=n; i++) {
        if(!indegree[i]){
            minHeap.insert(i);
        }
    }
    while(!minHeap.empty()) {
        int smallest = *minHeap.begin();
        topo.push_back(smallest);
        minHeap.erase(smallest);
        for(int v: adj[smallest]) {
            indegree[v]--;
            if(indegree[v] == 0) {
                minHeap.insert(v);
            }
        }
    }
    return topo;
}
