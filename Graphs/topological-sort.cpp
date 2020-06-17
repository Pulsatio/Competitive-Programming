
vi toposort;
vi adj[MAX];
int visit[MAX];

void dfs(int u){
	visit[u] =1;
	for(int v:adj[u]){
		if(visit[v]) continue;
		dfs(v);
	}
	toposort.push_back(u);
}

void topological_sort(int n){
	f(i,0,n){
		if(!visit[i]){
			dfs(i);
		}
	}
	reverse(all(toposort));
}