//GCC46401
//c-common.c

//bad input contains a long expression:
//QStringList function_list = 
//                 QStringList() << "abasep" <<"abs" ... 

static bool
candidate_equal_p (const_tree x, const_tree y)
{
    return (x == y) || (x && y && operand_equal_p (x, y, 0));
}

//comments from developers: 
//"No point tracking CALL_EXPRs that aren't ECF_CONST  
//(because  then operand_equal_p fails anyway) nor  
//STRING_CSTs (which can't be written into)"
static void 
merge_tlist(struct tlist **to, struct tlist *add, int copy)
{
    ...
    for (tmp2 = *to; tmp2; tmp2 = tmp2->next)
        if (candidate_equal_p (tmp2->expr, add->expr))
        { 
            found = 1;
            if (!tmp2->writer)
                tmp2->writer = add->writer;
        }
    ...
}

