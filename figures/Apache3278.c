1  notified = false;
2  while(!notified) {
3    rc = pthread_cond_timedwait(
4              &cond, &lock, &timeToWait);
5    if(rc == ETIMEDOUT) {
6      break;
7    }
8  }              
