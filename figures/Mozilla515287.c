//Mozilla515287 & Patch
//content/base/src/nsXMLHttpRequest.cpp

//This was not a bug until Web 2.0, where doing   
//garbage collection (GC) after every XMLHttpRequest(XHR) 
//is too frequent.
nsXMLHttpRequest::OnStopRequest(...)
{
  ...
-  mScriptContext->GC();
}
