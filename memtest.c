// Hunter Price
#include "types.h"
#include "stat.h"
#include "user.h"

void
memtest() {
  // create a pointer on the heap then calculate the page table it belongs to
  // assuming the page size is 0x1000
  int *ptr = malloc(sizeof(int));
  void *page_addr = (void*)ptr - ((uint)ptr % 0x1000);

  // print general info
  printf(1, "----------------------------------------------------------------\n");
  printf(1, "testing with page that starts at memory address: 0x%p\n\n",page_addr);
  printf(1, "----------------------------------------------------------------\n");

  // test default behavior
  printf(1, "attempting to write over default memory at address: 0x%p\n", ptr);
  *ptr = 1;
  printf(1, "wrote over address: *0x%p = %d\n\n", ptr, *ptr);
  printf(1, "----------------------------------------------------------------\n");

  // test unprotected behavior
  mprotect(page_addr, 1);
  munprotect(page_addr, 1);
  printf(1, "attempting to write over unprotected memory at address: 0x%p\n", ptr);
  *ptr = 2;
  printf(1, "wrote over address: *0x%p = %d\n\n", ptr, *ptr);
  printf(1, "----------------------------------------------------------------\n");

  // test protected behavior
  mprotect(page_addr, 1);
  printf(1, "attempting to write over protected memory at address: 0x%p\n", ptr);
  *ptr = 3;
  printf(1, "wrote over address: *0x%p = %d\n\n", ptr, *ptr);
  printf(1, "----------------------------------------------------------------\n");
}

int
main() {
  memtest();
  exit();
}
