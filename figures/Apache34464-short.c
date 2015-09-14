//Apache#34464 & Patch
//TelnetTask.java

+  int i = -k.length();
-  while (s.indexOf(k) == -1)
+  while (i++<0 || 
+      s.substring(i).indexOf(k)==-1)
   {s.append (nextchar());}


