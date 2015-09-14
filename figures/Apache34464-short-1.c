//A PPP we found in the latest Struts

while (1) {
-  n = s.indexOf("%\\>");
+  n = s.substring(n+2).indexOf("%\\>");
   if (n < 0) break;
   ... // replace "%\\>" by "%>" and continue
}

