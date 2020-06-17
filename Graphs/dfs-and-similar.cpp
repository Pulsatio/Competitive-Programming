


vi adj[MAX];
int visited[MAX];



void dfs_tree(int u,int father){
    f(i,0,adj[u].size()){
        int v = adj[u][i];
        if(v == father)  continue;    
        dfs_tree(v,u);
    }
} 

void dfs(int u){
    visit[u] = 1;
    f(i,0,adj[u].size()){
        int v = adj[u][i];
        if(visit[v]) continue; 
        dfs(v);
    }

}

void bfs(int root){
    queue<int> q;
    visit[root]=1;
    q.push(root)
    while(q.empty()){
        int u = q.front(); q.pop();
        f(i,0,adj[u].size()){
            int v = adj[u][i];
            if(!visit[v]) {
                visit[v] = 1;
                q.push(v)
            }
         }
    }
}