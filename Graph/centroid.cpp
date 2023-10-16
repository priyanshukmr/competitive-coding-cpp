vector<int> adj[SZ];
int sub[SZ], n;

void dfs_sub(int u, int p) {
    sub[u]=1;
    for(int v: adj[u]) {
        if(v!=p) {
            dfs_sub(v, u);
            sub[u] += sub[v]; 
        }
    }
}

int centroid(int u, int p) {
    for(int v: adj[u]) {
        if(v!=p) {
            if(sub[v]>n/2) {
                return centroid(v, u);
            }
        }
    }
    return u;
}
