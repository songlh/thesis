1   //Apache34463
2   //java.lang.String
3   static int indexOf(char[] source, int sourceCount, char[] target, int targetCount ) 
4   {
5       ...
6       char first  = target[targetOffset];
7       int max = sourceCount - targetCount;
8       for (int i = 0; i <= max; i++) {
9          // Look for first character.
10          if (source[i] != first) {
11              while (++i <= max && source[i] != first);
12          }
13          // Found first character now look at the rest
14          if (i <= max) {
15              int j = i + 1;
16              int end = j + targetCount - 1;
17              for (int k = 1; j < end && source[j] == target[k]; j++, k++);
18              if (j == end) {
19                  /* Found whole string. */
20                  return i ;
21              }
22          }
23      }
24      return -1;
25  }
26  //TelnetTask.java
27  public void waitForString(...)
28  {
29 +    int windowIndex = -s.length();
30 -    while (sb.toString().indexOf(s) == -1) {
31 +    while (windowIndex++ < 0 || sb.substring(windowIndex).indexOf(s) == -1) {
32          sb.append((char) is.read());
33      }
34  }
