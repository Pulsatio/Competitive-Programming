
// general Segment Tree

struct Node{
	// information
};

Node null_node;

Node op(Node l,Node r){
	Node ans;

	return ans;
}


// struct for more beauty?

ll n;
Node tree[MAX*2];
void build(){
	af(i,n-1,0) tree[i] = op(tree[i<<1],tree[i<<1 | 1]);
}

Node query(ll l,ll r){
	Node ans = null_node;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1) ans = op(tree[l++],ans);
		if(r&1) ans = op(tree[--r],ans);
	}
	return ans;
}

void update(ll ind,Node x){
	tree[ind+=n] = x;
	while(ind){
		ind>>=1;
		tree[ind] = op(tree[ind<<1],tree[ind<<1|1]);
	}
}