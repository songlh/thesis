//MySQL#26527 & Patch
//sql/ha_partition.cc

void ha_partition::start_bulk_insert(ha_rows rows)
{
    ...
-    if (!rows)
-    {   //slow path where caching is not used
-        DBUG_VOID_RETURN;
-    }
-    rows = rows/m_tot_parts + 1;
+    rows = rows ? (rows/m_tot_parts + 1) : 0;
    ...
    //fast path where caching is used
    DBUG_VOID_RETURN;
}
