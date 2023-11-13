/* 
	Algo: https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm#Algorithm
	Problem: [CSES Shortest Routes-2] https://cses.fi/problemset/result/7683091/
*/


int shortest[SZ][SZ];
 
void floyd_warshall() {
    for(int i = 0; i <= n; i++) 
		for(int j = 0; j <= n; j++) 
            shortest[i][j] = i==j ? 0 : MAXX;
    
	for(int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		shortest[u][v] = min(shortest[u][v], w);
		shortest[v][u] = min(shortest[v][u], w);
	}
	for(int k = 1; k <=n ; k++) 
		for(int i = 1; i <=n ; i++) 
			for(int j = 1; j <=n ; j++) 
				shortest[i][j] = min(shortest[i][j], shortest[i][k] + shortest[k][j]);
}
