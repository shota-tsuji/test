#include <stdio.h>
#include <stdlib.h>

int main()
{
	double random_value;
	const int loop = 10;
	int i=0;
	srand(0);
	
	for(i=0; i<loop; ++i){
		//random_value = (double)rand() / RAND_MAX*2.0-1.0; //float in range -1 to 1
		random_value = (double)rand() / RAND_MAX*4.0 -2.0; //float in range -1 to 1
		printf( "%f\n", random_value );
	}

	return 0;
}
