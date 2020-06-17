
// for idempotent function (minimum,maximum,gcd,etc)

ll lg[MAX];


ll st[MAX][K+1],n;


void init(){
	
	lg[1] = 0;
	f(i,2,MAX) lg[i] = lg[i/2] +1;

	f(i,0,n) st[i][0] = // initial array
	f(x,1,K+1){
		f(i,0,n){
			if(i + (1LL<<x)>n) break;
			st[i][x] =  min (st[i][x-1] , st[i + 1LL<<(x-1) ][x-1]);
		}
	}
}

ll query(ll l,ll r){
	ll aux = lg[r - l + 1];
	ll ans = min(st[l][aux], st[r - (1 << aux) + 1][aux]);
	return ans;
}

