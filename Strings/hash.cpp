



ll hashing(string s,ll m=1e9+7,ll p=31){
	ll hashv=0,pow_p=1;
	f(i,0,s.size()){
		(hashv+=pow_p*(s[i]-'a'+1))%=m;
		(pow_p*=p)%=m;
	} 
	return hashv;
}