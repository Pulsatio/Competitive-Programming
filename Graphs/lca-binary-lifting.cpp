int tie[MAX],tout[MAX],cont=0,anc[MAX][20];

void dfs(int u,int f){
	
	anc[u][0] = f;

	f(i,1,20) anc[u][i]= anc[ anc[u][i-1] ][i-1];

	tin[u]=cont++;
	f(i,0,adj[u].size()){
		int v=adj[u][i];	
		if(v==f) continue;
		dfs(v,u);
	}
	tout[u]=cont++;
}

bool is_ancester(int u,int v){
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u,int v){
	if(is_ancester(u,v)) return u;
	if(is_ancester(v,u)) return v;
	af(i,20,0){
		if(!is_ancester(anc[u][i],v)) u=anc[u][i];
	}
	return anc[u][0];
}