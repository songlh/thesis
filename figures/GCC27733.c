//expmed.c
struct alg_hash_entry {
-  unsigned int t;
+  unsigned HOST_WIDE_INT t;
}

void 
synth_mult(...unsigned HOST_WIDE_INT t, ...)
{
  hash_index = t ...;
  if (alg_hash[hash_index].t == t ...)
  {
    ...
    return ;
  }
  ...
  //recursive computation
}
