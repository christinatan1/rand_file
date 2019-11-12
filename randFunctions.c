#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include "randHeaders.h"

int randNum(){
  int fd = open("/dev/random", O_RDONLY);
  int output;
  read(fd, &output, sizeof(output));
  if (fd < 0){
    printf("errno: %d error %s\n", errno, strerror(errno));
  }
  close(fd);
  return output;
}
