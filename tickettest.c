/***************************************/\
// Hunter Price
#include "pstat.h"
#include "types.h"
#include "user.h"

void
tickettest(void) {
  int i, pid;

  for(i = 0; i < 3; i++) {
    pid = fork();
    if (pid > 0)
      break;
  }
  if(pid == 0)
    exit();
  if (i == 0)
    settickets(30);
  if (i == 1)
    settickets(20);
  if (i == 2)
    settickets(10);
  for( ; ; ){ }
}

int
main(int argc, char *argv[])
{
  tickettest();
  exit();
}
/***************************************/