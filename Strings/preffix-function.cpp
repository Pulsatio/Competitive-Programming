

void preffixFunction(ll pf[],string s){
	f(i,0,s.size()) pf[i]=0;
	f(i,1,s.size()){
		ll j=pf[i-1];
		while(j!=0 && s[i]!=s[j]) j=pf[j-1];
		if(s[i]==s[j]) j++;
		pf[i]=j;
	}
}


void zFunction(ll z[],string s){
	ll n = (ll) s.size();
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}