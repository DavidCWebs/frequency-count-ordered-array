#ifndef	MATCH_COUNTS_H
#define MATCH_COUNTS_H
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "vector.h"

unsigned *getMatchCountsQuick(Vector v);
unsigned *getMatchCounts(Vector v);

#endif
