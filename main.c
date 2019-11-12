#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include "randHeaders.h"

int main(){

  //test: populate array with random numbers
  int randInts[20];
  printf("Generating random numbers: \n");
  int i;
  int num;
  for(i = 0; i <=10; i++){
    num = randNum();
    randInts[i] = num;
    printf("random %d: %d\n", i, num);
  }

  //test: write array to a file
  printf("Writing numbers to file ...\n");
  int fd = open("numbers.txt", O_WRONLY | O_CREAT, 0644);
  write(fd, randInts, sizeof(randInts));
  if (fd < 0){
    printf("errno: %d error: %s\n", errno, strerror(errno));
  }
  close(fd);

  //test: read file into new file
  printf("Reading numbers from file ...\n");
  int newNums[20];
  fd = open("numbers.txt", O_RDONLY);
  read(fd, newNums, sizeof(newNums));
  if (fd < 0){
    printf("errno: %d error: %s\n", errno, strerror(errno));
  }
  close(fd);

  //test: print contents of the second file
  printf("Verification that written values were the same...\n");
  int j;
  for (j = 0; j <= 10; j++){
    printf("random %d: %d\n", j, newNums[j]);
  }
}
