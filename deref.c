#include "types.h"
#include "stat.h"
#include "user.h"


int
main() {
  int *ptr = 0;
  *ptr = 10;
  int i = *ptr;
  printf(1, "%d\n", i);
  exit();
}