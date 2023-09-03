//Problem: https://cses.fi/problemset/task/1682/


int n,m;
vector<int> adj[SZ];
vector<int> rev_adj[SZ];
vector<int> finished;
vector<bool> vis(SZ, false);

void dfs(int u, vector<int> adj[], bool createFinish) {
    vis[u] = true;
    for(int v: adj[u]) {
        if(!vis[v]) {
            dfs(v, adj, createFinish);
        }
    }
    if(createFinish)
    finished.push_back(u);
}

vector<int> SCC_Kosaraju() {
    for(int i=1; i<=n; i++) {
        if(!vis[i]) dfs(i, adj, true);
    } 
    vector<int> scc;
    fill(vis.begin(), vis.end(), false);
    for(int i=n-1; i>=0; i--) {
        if(!vis[finished[i]]) {
            scc.push_back(finished[i]);
            dfs(finished[i], rev_adj, false);
        }
    }
    return scc;
}
