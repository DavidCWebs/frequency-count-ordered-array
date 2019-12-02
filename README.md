# Frequency Count in an Ordered Array

Notes on algorithmic efficiency.

The objective is to count the frequency of a value at each position in an ordered array. The result should be an array where each value corresponds to a frequency count of the element at the same position in the original array:

```c
// Data array:
int a[] = {1,1,1,2,3,4,4,5,5,5,5,6};
// Frequency count, to stdout:

Count at 0:	3
Count at 1:	3
Count at 2:	3
Count at 3:	1
Count at 4:	1
Count at 5:	2
Count at 6:	2
Count at 7:	4
Count at 8:	4
Count at 9:	4
Count at 10:	4
Count at 11:	1
```
The naive way to achieve this is to loop within a loop - step through each element in the array, and compare the element at this position with every other element in the array. 

```c
int a[] = {1,1,1,2,3,4,4,5,5,5,5,6};
size_t n = sizeof(a) / sizeof(a[0]);
int *result = calloc(n, sizeof(*result));
for (size_t i = 0; i < n; i++; {
	for (size_t j = 0; j < n; j++) {
		if (i == j) continue;
		if (a[i] == a[j]) {
			result[i]++;
		}
	}
}
``` 
This works, but it is very inefficient. If the array is ordered, there is a lot of double counting. If you're just running the routine very many times, and the array is not too large, the chances are it will work adequately well and you may not even notice a problem.

If the routine runs hundreds of thousands of times as part of your programme, you may run into difficulties.

The more efficient function steps through each element in the array and performs an equality check with the following element, keeping a running tally.

When a non-equal element is found in the next position, we loop over the previously counted elements and write the tallied value into the correct position in the result array:

```c
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
```
