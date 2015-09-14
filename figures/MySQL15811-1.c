//A PPP we found in the latest MySQL
//ibmysql/libmysql.c

//'end' is only used in the ismbchar checking
-  for (end=s; *end ; end++) ;
-  if (ismbchar(mysqlcs, s, end) )
+  if (ismbchar(mysqlcs, s, s 
                         + mysqlcs->mbmaxlen)



