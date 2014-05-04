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

int main(int argc, char** argv) 
{
  int reps, i, t, x;
  float percentage = 0;
  int m_count = 0;
  pid_t pid = getpid();

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
    percentage = (float) i / reps;
    percentage *= 100;
    if (percentage > 25 && m_count == 0 ||
	percentage > 50 && m_count == 1 ||
	percentage > 75 && m_count == 2) {
      printf("pid %d: %g%% done\n", pid, percentage);
      fflush(NULL);
      m_count ++;
    }
  }
  printf("pid %d: finished\n", pid);
}
