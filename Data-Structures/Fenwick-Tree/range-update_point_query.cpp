

ll tree[MAX],n;

void add(ll id,ll val) {
    while(id<=n){
        tree[id] += val;
    	id += (id & -id);
    }
}

void update(ll l, ll r,ll val) {
    add(l, val);
    add(r + 1, -val);
}

ll point_query(ll id) {
    ll ret = 0;
    while(id>0){
        ret += bit[idx];
    	id -= (id & -id);
    }
    return ret;
}