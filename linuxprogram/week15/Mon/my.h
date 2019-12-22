#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/time.h>
#include <wait.h>
#include <errno.h>
#include <pthread.h>
#include <limits.h>
#include <semaphore.h>
#define LOOP 10000000
#define NUM 4
#define TN 100
#define WRITER_FIRST
