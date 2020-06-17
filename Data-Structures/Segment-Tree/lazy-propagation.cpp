


ll arr[MAX],tree[MAX*4],lazy[4*MAX];

void push(ll node,ll l,ll r){
    if(lazy[node] == 0) return;
    tree[node] += (r - l + 1) * lazy[node];         
    if(l != r){
        lazy[node*2] += lazy[node];        
        lazy[node*2+1] += lazy[node];   
    } 
    lazy[node] = 0;               
    
}

void build(ll node,ll l,ll r){
    if(l==r){
        tree[node]=arr[l];
        return;
    }
    ll mid = (l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node] = tree[node*2]+ tree[node*2+1];
}

void update(ll node,ll l,ll r,ll i,ll j,ll v){
	// push lazy
    push(node,l,r);

    if(l>r || r<i || j<l ) return;  
    if(i<=l && r<=j){
        lazy[node] = v;
        push(node,l,r);
        return;
    }
    ll mid=(l+r)/2;
    update(node*2,l,mid,i,j,v);     
    update(node*2+1,mid+1,r,i,j,v);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(ll node,ll l,ll r,ll i,ll j){
    push(node,l,r);
    if(l>r || r<i || j<l) return 0;
    if(i<=l && r<=j) return tree[node];
    ll mid = (l+r)/2;
    return query(node*2,l,mid,i,j) + query(node*2+1,mid+1,r,i,j);
}



