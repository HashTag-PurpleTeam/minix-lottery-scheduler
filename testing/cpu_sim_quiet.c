/* cpu_sim.c
 * 
 * A program that simulates a CPU bound process.
 *
 * From assignment specs: "One test program should run continually
 * doing some sort of useless mathematical calculation. It should
 * periodically emit progress information including the process ID of
 * the current process and how much work has been done so far. This
 * program should take about 10 seconds when run in the normal MINIX
 * environment by itself (or allow command line arguments that control
 * how much work it does)."
 *
 * CREATED: Leland Miller
 */
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char** argv) 
{
	int reps, i, t, x;
	pid_t pid = getpid();
	time_t current_time;	

	current_time = time(NULL);
	printf("pid %d: started @ %s", pid, ctime(&current_time));

	if (argc != 2) {
		fprintf(stderr, "Usage: cpu_sim work_scale\n");
		exit(-1);
	}
	reps = atoi(argv[1]);

	for (i = 0; i < reps; ++i) {
		for (t = 250000000; t > 0; --t) {
			/* t is always a positive int */
			x = INT_MAX % t;
		}
	}
	current_time = time(NULL);
	printf("pid %d: finished @ %s", pid, ctime(&current_time));
}
