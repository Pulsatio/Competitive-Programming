

struct FenwickTree{
	// 1-indexed
	ll tree[MAX],n;

	void init(){
		f(i,0,n) tree[i] = 0;
	}

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
};

// 1-indexed

FenwickTree Bit1,Bit2;

void update(ll l,ll r,ll v){
	Bit1.add(l,v);
	Bit1.add(r+1,-v);
	Bit2.add(l,v*(l-1));
	Bit2.add(r+1,-v*r),
}

ll accum(ll x){
	return Bit1.accum(x)*x - Bit2.accum(x);
}

ll query(ll l,ll r){
	return accum(r)-accum(l-1);
}