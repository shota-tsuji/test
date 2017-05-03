int ibl = n / 2;
int ib, jb, kb;
for(ib=0; ib<n; ib+=ibl){
	for(jb=0; jb<n; jb+=ibl){
		for(kb=0; kb<n; kb+=ibl){
			for(i=ib; i<ib+ibl; ++i){
				for(j=jb; j<jb+ibl; ++j){
					for(k=kb; k<kb+ibl; ++k){
					C[i][j]+=A[i][k]*B[k][j];
					}
				}
			}
		}
	}
}
