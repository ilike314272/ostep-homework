#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
  close(STDOUT_FILENO);
  FILE *file = fopen("./hw.output", "w");
  int rc = fork();

  volatile int x = 0;

  if (rc < 0) {
    fprintf(stderr, "Fork failed.\n");
    exit(1);
  } else if (rc == 0) {
    while (x < 10) {
      printf("PID %d: %d\n", (int) getpid(), x);
      x++;
    }
  } else {
    //int rc_wait = wait(NULL);
    while (x < 10) {
      printf("PID %d: %d\n", (int) getpid(), x);
      x++;
    }
  }

  return 0;
}
