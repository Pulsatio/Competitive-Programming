



ii twohashing(string s,ll m1=1e9+7,ll m2=1e9+33,ll p=31,ll q=43){
	ll hash1=0,hash2=0,pow_p=1,pow_q=1;
	f(i,0,s.size()){
		(hash1+=pow_p*(s[i]-'a'+1))%=m1;
		(hash2+=pow_q*(s[i]-'a'+1))%=m2;
		(pow_p*=p)%=m1;
		(pow_q*=q)%=m2;
	} 
	return {hash1,hash2};
}