//Mozilla#490742 & Patch
//browser/components/places/src/nsPlacesTransactionsService.js 

//doTransact saves one tab into 'bookmark' SQLite Database.
//Firefox hangs @ 'bookmark all (tabs)'
for (var i = 0; i < tabs.length; ++i) 
{
  ...
-  tabs[i].doTransact();
}

+ doAggregateTransact(tabs);
