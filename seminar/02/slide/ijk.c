for(i=0; i<n; ++i){
	for(j=0; j<n; ++j){
		for(k=0; k<n; ++k){
			C[i][j] += A[i][k] * B[k][j];
		}
	}
}
