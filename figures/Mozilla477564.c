1   //Mozilla477564
2   //nsSessionStore.js
3 
4   generate: function sss_xph_generate(aNode)
5   {
6       ...
7       for (let n = aNode; (n = n.previousSibling); )
8           if (n.localName == aNode.localName && n.namespaceURI ==  
9             aNode.namespaceURI && (!nName || n.name == nName))
10              count++;
11      //count will be used to generate a ID 
12      //for the aNode
13      ...
14  }
