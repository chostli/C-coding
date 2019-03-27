#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#define BUFFER_SIZE 1024
#ifndef __ADD_GET__
#define __ADD_GET__
int GetFileType(mode_t st_mode,char*resp);

#endif
