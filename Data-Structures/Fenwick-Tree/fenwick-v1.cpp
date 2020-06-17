
// 1-indexed
ll tree[MAX],n;

ll accum(ll id){
	ll ret = 0;
	while(r>0){
		id += tree[id];
		id -= (id & -id);
	}
	return ret;
}

ll sum(ll l,ll r){
	return accum(r)-accum(l-1);
}

void add(ll id,ll aum){
	while(id<=n){
		tree[id]+=aum;
		id += (id & -id);
	}
}
