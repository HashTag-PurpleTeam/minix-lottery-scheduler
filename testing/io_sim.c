/* io_sim.c
 * 
 * A program that simulates an IO bound process.
 * 
 * From assignment specs: "A second test program should open a file,
 * add up every byte into a checksum, then save the input data back
 * into a new copy of the file and print out the checksum (reading and
 * writing blocks of 1024 bytes). This test program simulates an IO
 * bound process with some minor CPU use."
 *
 * CREATED: Leland Miller
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  FILE *in = fopen(argv[1], "rb");
  FILE *out = fopen(argv[2], "wb");
  char buffer[1024];
  int count = 0;
  int i;
  int checksum = 0;

  if (argc != 3) {
    fprintf(stderr, "Usage: io_sim in_file out_file\n");
    exit(-1);
  }

  do {
    count = fread(&buffer, sizeof (char), sizeof buffer, in);
    for (i = 0; i < count; ++i) {
      checksum += buffer[i];
    }
    fwrite (&buffer, sizeof(char), count, out);
  } while (count != 0);
  printf("Checksum: %d\n", checksum);	

}
