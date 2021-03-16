/***************************************/
// Hunter Price
#include "pstat.h"
#include "types.h"
#include "user.h"

void
ps(void){
  // declare vars
  int i;
  struct pstat *p;

  // allocate space for pstat struct and have it populated by the kernel
  p = malloc(sizeof (struct pstat));
  if (getpinfo(p) < 0)
    printf(1, "ERROR: could not get the pstat struct from kernel\n");

  // print out the contents of the pstat struct
  for (i = 0; i < NPROC; i++) {
    printf(0, "inuse: %d, pid: %d, tickets: %d, ticks: %d\n", p->inuse[i], p->pid[i], p->tickets[i], p->ticks[i]);
  }
}

int
main(int argc, char *argv[])
{
  ps();
  exit();
}
/***************************************/