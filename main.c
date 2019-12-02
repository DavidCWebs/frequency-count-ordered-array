#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "match-counts.h"

#define DEFAULT_N_TRIALS 100000

#ifdef QUICK 
#define Q 1
#else
#define Q 0
#endif

int main(int argc, char **argv)
{
	printf("QUICK = %d\n", Q);
	int quickFunc = Q;
	unsigned *(*func)(Vector);
	func = quickFunc ? &getMatchCountsQuick : &getMatchCounts;  
	size_t nTrials;
	if (argc == 2) {
	
		nTrials = strtol(argv[1], NULL, 10);
		if ((errno == ERANGE && (nTrials == LONG_MAX || nTrials == LONG_MIN))
				|| (errno != 0 && nTrials == 0)) {
	               perror("strtol");
		       exit(EXIT_FAILURE);
		}
	} else {
		nTrials = DEFAULT_N_TRIALS;
	}
	int a[] = {1,1,1,2,3,4,4,5,5,5,5,6};
	Vector v1 = {a, sizeof(a) / sizeof(a[0])};
//	unsigned *result = {0};
	unsigned *result = calloc(v1.n, sizeof(*result));
	for (size_t i = 0; i < nTrials; i++) {
		result = func(v1);
	}
	for (size_t i = 0; i < v1.n; i++) {
		printf("Count at %lu:\t%u\n", i, result[i]);
	}
	return EXIT_SUCCESS;
}
