


// search lower bound in a array of the preffix sums
// after declarate BIT
// https://codeforces.com/blog/entry/61364

ll tree[N],n; // BIT array

ll K = 20 //log(n)  
ll bit_search(ll val){
	ll sum = 0;
	ll pos = 0;
	
	af(i,K,0){
		if(pos + (1 << i) < n && sum + tree[pos + (1 << i)] < v)
		{
			sum += tree[pos + (1 << i)];
			pos += (1 << i);
		}
	}

	return pos + 1; // +1 because 'pos' will have position of largest value less than 'v'
}





