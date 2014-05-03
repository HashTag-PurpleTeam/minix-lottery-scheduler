/* cpu_sim.c
 * 
 * A program that simulates a CPU bound process.
 *
 * CREATED: Leland Miller
 */
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

int main(int argc, char** argv) {
	int reps;
	int i;
	int t;
	int x; 
	float percentage = 0;
	int m_count = 0;

	reps = atoi(argv[1]);

	for (i = 0; i < reps; ++i) {
		for (t = 250000000; t > 0; --t) {
			/* t is always a positive int */
			x = INT_MAX % t;
		}
		percentage = (float) i / reps;
		percentage *= 100;
		if (percentage > 25 && m_count == 0 ||
		    percentage > 50 && m_count == 1 ||
		    percentage > 75 && m_count == 2) {
			printf("pid : %g%% done\n",  percentage);
			fflush(NULL);
			m_count ++;
		}
	}
	printf("pid : finished\n");
}
