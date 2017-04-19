time_s = omp_get_wtime();
for(i=0; i<n; ++i){
	for(j=0; j<n; ++j){
		for(k=0; k<n; ++k){
			C[i][j] += A[i][k] * B[k][j];
		}
	}
}
whole_time = omp_get_wtime() - time_s;

double num_cluc = 2.0 * pow(n, 3);
double gflops = num_cluc / ( pow(10.0, 9) *  whole_time);
