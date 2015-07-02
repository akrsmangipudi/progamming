int lengthOfLastWord(char* s)
{
    int retVal = 0;
    
    unsigned int len = strlen(s);
    
    if( len == 0 )
    {
        return retVal;
    }
    
    unsigned int idx = 0;

    while( idx < len )
    {
        if( s[ idx ] == ' ' )
        {
            idx++;
        }
        else
        {
            break;   
        }
    }
    
    if( idx == len )
    {
        return retVal;
    }
    
    // At this point idx is pointing to the first word in the input string ( it might be the last word too )
    unsigned int wordStart = 0, wordEnd = 0;
    
    while( idx < len )
    {
        if( s[idx] == ' ' )
        {
            while( s[ idx ] == ' ' && s[ idx ] != '\0' )
            {
                idx++;
            }
            if( s[ idx ] == '\0' )
            {
                break;
            }
        }
        else
        {
            wordStart = idx;
            
            while( s[ idx ] != ' ' && s[ idx ] != '\0' )
            {
                idx++;
            }
            
            wordEnd = idx - 1;
            
            if( s[ idx ] == '\0' )
            {
                break;
            }
        }
    }
    
    return wordEnd - wordStart + 1;   
}
