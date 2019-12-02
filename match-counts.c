#include "match-counts.h"

/**
 * If the array is sorted, this is much more efficient than looping within a loop.
 * */
unsigned *getMatchCountsQuick(Vector v)
{
	unsigned *result = calloc(v.n, sizeof(*result));
	size_t i = 0, tally = 1;
	while (i < v.n) {
		if (i < v.n - 1 && v.array[i] == v.array[i + 1]) {
			tally++;	
		} else {
			for (size_t j = i + 1 - tally; j <= i; j++) {
				result[j] = tally;
			}
			tally = 1;
		}
		i++;
	}
	return result;
}

/**
 * Naive implementation - loop within a loop to check for duplicate values.
 * The array need not be sorted for this to work.
 * */
unsigned *getMatchCounts(Vector v)
{
	unsigned *result = calloc(v.n, sizeof(*result));
	for (size_t i = 0; i < v.n; i++) {
		result[i]++;
		for (size_t j = 0; j < v.n; j++) {
			if (i == j) continue;
			if (v.array[i] == v.array[j]) {
				result[i]++;
			}
		}
	}
	return result;
}

