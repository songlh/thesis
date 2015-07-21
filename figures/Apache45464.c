//Apache#45464
//modules/dav/fs/repos.c

status = apr_stat(&fsctx->info1.finfo, fsctx->path1.buf,
-                 APR_FINFO_NORM | APR_FINFO_LINK, pool);
+                 APR_FINFO_TYPE | APR_FINFO_LINK, pool);
