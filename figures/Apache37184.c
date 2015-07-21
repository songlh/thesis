//Project.java
public synchronized void 
addBuildListener(BuildListener listener) {
+  if (!newListeners.contains(listener)) {
    newListeners.addElement(listener);
+  }
}

private void 
fireMessageLoggedEvent(...) {
  ...
  while (iter.hasNext()) {
    BuildListener listener 
         = (BuildListener) iter.next();
    listener.messageLogged(event);
  }
}
