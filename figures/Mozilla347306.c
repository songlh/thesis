//jsscript.c
jssrcnote *
js_GetSrcNote(JSScript *script, jsbytecode *pc)
{
  ...
  for (sn = SCRIPT_NOTES(script); 
       !SN_IS_TERMINATOR(sn); sn = SN_NEXT(sn)) {
    offset += SN_DELTA(sn);
    if (offset == target && SN_IS_GETTABLE(sn))
       return sn;
  }
  return NULL;
}
