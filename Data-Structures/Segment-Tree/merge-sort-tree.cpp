

// merge sort tree 

// find how numbers less of k in a query(l,r) 

// struct for more beauty?

ll n;

vi tree[MAX*2];

void merge(ll node,ll l,ll r){
	ll x = 0,y = 0;
	while(x<tree[l].size() || y<tree[r].size()){
		if(x==tree[l].size()) tree[node].push_back(tree[r][y]),y++;
		else if(y==tree[r].size()) tree[node].push_back(tree[l][x]),x++;
		else if(tree[l][x]<tree[r][y]) tree[node].push_back(tree[l][x]),x++;
		else  tree[node].push_back(tree[r][y]),y++;
	}
}

void build(){
	f(i,0,n) tree[i+n].push_back( /* initial array */)
	af(i,n-1,0) merge(i,i<<1,i<<1 | 1);
}

ll kth(ll node,ll k){
	return lower_bound(all(tree[node]),k) - tree[node].begin();
}

ll query(ll l,ll r,ll k){
	ll ans = 0;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1) ans +=  kth(l,k),l++;
		if(r&1) r--,ans +=  kth(r,k);
	}
	return ans;
}

// update ?
