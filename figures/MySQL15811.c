//MySQL#15811 & Patch
//strings/ctype-mb.c


-  char * end = str + strlen(str);
-  if(ismbchar(cs, str, end))
+  if(ismbchar(cs, str, str 
                 + cs->mbmaxlen))
