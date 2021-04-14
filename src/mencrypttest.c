// Test that fork fails gracefully.
// Tiny executable so that the limit can be filling the proc table.

#include "types.h"
#include "stat.h"
#include "user.h"
#include "ptentry.h"

#define PGSIZE 4096

void
printf(int fd, const char *s, ...)
{
  write(fd, s, strlen(s));
}

void
mencrypttest(void)
{

  char *ptr = sbrk(PGSIZE); // Allocate one page
  mencrypt(ptr, 1); // Encrypt the pages
  struct pt_entry pt_entry; 
  getpgtable(&pt_entry, 1); // Get the page table information for newly allocated page
  
  
  
  printf(1, "mencrypt test OK\n");
}

int
main(void)
{
  mencrypttest();
  exit();
}
