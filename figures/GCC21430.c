//tree-ssa-operands.c
static inline void
correct_use_link(...)
{
  ...
  //the same link link will be processed by 
  //different loop instances during a buggy run.
  while (prev->use != NULL || prev->stmt == NULL)
    prev = prev->prev;

  root = prev->stmt;
  ...
}
