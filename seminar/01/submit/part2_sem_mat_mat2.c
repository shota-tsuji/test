void fill_matrix(double **matrix, int n)
{
	int i, j, val = 1;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			matrix[i][j] = (double)rand() / RAND_MAX*2.0 -1.0;
		}
	}
}
