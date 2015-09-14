//MySQL#38941 & Patch
//mysys/thr_mutex.c

//random() is a serialized global-mutex-protected 
//glibc function.
int fastmutex_lock(...)
{
  ...
-  maxdelay += (double)random();
+  maxdelay += (double)park_rng();
  ...
}
