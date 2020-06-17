struct Edge{ 
	int u,v,w;
	bool operator<(const Edge &other){
		return w<other.w;
	}
};

int find(int x){ return p[x]==x? x : find(p[x]); }

void initialize(int n){ f(i,0,n+1) p[i]=i; }

void uni(int a,int b){
	int x=find(a),y=find(b);
	if(x==y) return;
	p[x]=y;
} 

Edge edges[MAX]

void MST(int m){
	sort(edges,edges+m);
	ll mst=0;
	f(i,0,m){
		if(find(edges[i].u)!=find(edges[i].v)){
			uni(edges[i].u,edges[i].v);
			mst+=edges[i].w;
		}
	}

}
