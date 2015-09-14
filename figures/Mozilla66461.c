//Mozilla#66461 & Patch
//gfx/src/gtk/nsImageGTK.cpp

//When the input figure is transparent, mIsSpacer will be true.
//The patch conditionally skips nsImageGTK::Draw().
NS_IMETHODIMP nsImageGTK::Draw(...)
{
  ...
+  if ((mAlphaDepth==1) && mIsSpacer)
+    return NS_OK;
  ...
  //render the input figure
}
