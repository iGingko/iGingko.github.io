#include <stdio.h>
#include <gsl/gsl_block.h>

int
main (void)
{
  gsl_block * b = gsl_block_alloc (100);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  printf ("length of block = %u\n", b->size);
  printf ("block data address = %#x\n", b->data);

  gsl_block_free (b);
  return 0;
}
