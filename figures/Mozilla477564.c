1  //nsSessionStore.js
2  generate: function sss_xph_generate(aNode)
3  {
4    ...
5    for (let n = aNode; (n = n.previousSibling); )
6      if (n.localName == aNode.localName 
7          && n.namespaceURI == aNode.namespaceURI 
8          && (!nName || n.name == nName))
9        count++;
10   //count will be used to generate a ID 
11   //for the aNode
12   ...
13 }
