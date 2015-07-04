void toLower( char *s )
{
    while( *s != '\0' )
    {
        // Current character is an upper case character.
        if( ( *s - 'A' >= 0 ) && ( *s - 'A' <= 25 ) )
        {
            *s = *s - 'A' + 'a';
        }
        s++;
    }
}

bool isPalindrome(char* s)
{
    if( *s == '\0' )
    {
        return true;
    }
    
    // After this step, all upper case characters in the input string would have been converted to lower case.
    toLower( s );
    
    unsigned int front = 0, back = strlen( s ) - 1;
    
    while( front < back )
    {
        //  Special character.
        if( ! ( ( ( s[ front ] - 'a' >= 0 ) && ( s[ front ] - 'a' <= 25 ) ) || ( ( s[ front ] - '0' >= 0 ) && ( s[ front ] - '0' <= 9 ) ) ) )
        {
            front++;
            continue;
        }
        
        if( ! ( ( ( s[ back ] - 'a' >= 0 ) && ( s[ back ] - 'a' <= 25 ) ) || ( ( s[ back ] - '0' >= 0 ) && ( s[ back ] - '0' <= 9 ) ) ) )
        {
            back--;
            continue;
        }
        
        if( s[ front ] != s[ back ] )
        {
            return false;
        }
        
        front++;
        back--;
    }
    return true;
}
