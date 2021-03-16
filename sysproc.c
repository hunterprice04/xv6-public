#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
/***************************************/
#include "pstat.h"
/***************************************/

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

/***************************************/
// implements the getpinfo system call getting
// the pointer from the parameters and passing
// it to the getpinfo function
int
sys_getpinfo(void)
{
  char *p;

  if(argptr(0, &p, sizeof(struct pstat)) < 0)
    return -1;
  return getpinfo((struct pstat *)p);
}
/***************************************/

/***************************************/
// implements the settickets system call getting
// and int from the parameters and passing it
// to the settickets function
int
sys_settickets(void)
{
  int n;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  n = settickets(n);
  release(&tickslock);

  return n;
}
/***************************************/
