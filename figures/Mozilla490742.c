// nsPlacesTransactionsService.js 
for (var i = 0; i < _childTransactions.length; ++i) 
{
-  var txn = _childTransactions[i];
-  txn.wrappedJSObject.id = _id;
-  txn.doTransaction();
+  childTransactions[i].wrappedJSObject.id = _id;
}

+ let aggregateTxn = 
+             new placesAggregateTransactions(...)
+ aggregateTxn.doTransaction();
