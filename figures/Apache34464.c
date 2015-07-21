0   //java.lang.String
1   static int 
2   indexOf(char[] source, int sourceCount,
3           char[] target, int targetCount ) 
4   {
5     ...
6     char first  = target[targetOffset];
7     int max = sourceCount - targetCount;
8
9     for (int i = 0; i <= max; i++) {
10      // Look for first character.
11      if (source[i] != first) {
12        while (++i <= max && source[i] != first);
13      }
14
15      // Found first character
16      //now look at the rest of v2
17      if (i <= max) {
18        int j = i + 1;
19        int end = j + targetCount - 1;
20        for (int k = 1; j < end && source[j] == 
21                 target[k]; j++, k++);
22
23        if (j == end) {
24          /* Found whole string. */
25          return i ;
26        }
27      }
28    }
29    return -1;
30  }
31
32  //TelnetTask.java
33  public void waitForString(...)
34  {
35 +  int windowIndex = -s.length();
36 -  while (sb.toString().indexOf(s) == -1) {
37 +  while (windowIndex++ < 0 || 
38 +   sb.substring(windowIndex).indexOf(s) == -1){
39      sb.append((char) is.read());
40    }
41  }
