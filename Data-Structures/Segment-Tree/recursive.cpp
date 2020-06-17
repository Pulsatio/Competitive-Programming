

struct Node{
	// information
};

Node null_node;

Node op(Node l,Node r){
	Node ans;
	// operation with nodes
	return ans;
}

// struct for more placer

ll n;
Node tree[MAX*4];

void build(ll node,ll l,ll r){
	if(l==r){
		tree[node] =  // initial state;
		return;
	}
	ll mid = (l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node] = op(tree[node*2],tree[node*2+1]);  
}

Node query(ll node,ll l,ll r,ll i,ll j){
	if(i<=l && r<=j) return tree[node];
	if(l>r || r<i || j<l) return null_node;
	ll mid = (l+r)/2;
	return op(query(node*2,l,mid,i,j),query(node*2+1,mid+1,r,i,j));
}

void update(ll node,ll l,ll r,ll ind,Node val){
	if(l==r){
		tree[node] = val;
		return;
	}
	ll mid = (l+r)/2;
	if(ind<=mid)
		update(node*2,l,mid,ind,val);
	else 
		update(node*2+1,mid+1,r,ind,val);
	tree[node] = op(tree[node*2],tree[node*2+1]);
}




