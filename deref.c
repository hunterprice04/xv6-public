/***********************************/
// Hunter Price
#include "types.h"
#include "stat.h"
#include "user.h"

void
deref() {
  int *ptr = 0;

  printf(1, "----------------------------------------------------------------\n");
  printf(1, "attempting to dereference memory address: 0x%x\n", ptr);
  printf(1, "%d\n", *ptr);
}


int
main() {
  deref();
  exit();
}
/***********************************/
