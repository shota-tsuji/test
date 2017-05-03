for(k=0; k<n; ++k){
	for(j=0; j<n; ++j){
		for(i=0; i<n; ++i){
			C[i][j] += A[i][k] * B[k][j];
		}
	}
}
