void reverseString( char *str )
{
    unsigned int i = 0;
    
    while( i < strlen(str)/2 )
    {
        char temp     = str[ i ];
        str[ i ] = str[ strlen(str) - 1 - i ];
        str[ strlen(str) - 1 - i ] = temp;
        i++;
    }
}

void CalculateSumAndCarry( unsigned int *sum, unsigned int *carry, unsigned int currSum )
{
    switch( currSum )
    {
        case 0:
            *sum   = 0;
            *carry = 0;
            break;
        
        case 1:
            *sum   = 1;
            *carry = 0;
            break;
        
        case 2:
            *sum   = 0;
            *carry = 1;
            break;
        
        case 3:
            *sum   = 1;
            *carry = 1;
            break;
    }
}

char* addBinary(char* a, char* b)
{
    if( *a == '\0' )
    {
        return b;
    }

    if( *b == '\0' )
    {
        return a;
    }

    reverseString( a );
    reverseString( b );

    unsigned int len1 = strlen( a );
    unsigned int len2 = strlen( b );

    unsigned int len = ( len1 > len2 ) ? len1 : len2;
    
    char *result = (char *)malloc( len + 1 );
    memset( result, 0, len + 1 );
    
    unsigned int idx   = 0;
    unsigned int sum   = 0;
    unsigned int carry = 0;
    
    while( *a != '\0' && *b != '\0' )
    {   
        unsigned int currSum = carry + ( *a - '0' ) + ( *b - '0' );
        CalculateSumAndCarry( &sum, &carry, currSum );
        result[ idx ] = sum + '0';
        printf("\n %c \n", result[ idx ] );
        idx++;
        a++;
        b++;
    }   
    
    while( *a != '\0' && *b == '\0' )
    {   
        unsigned int currSum = carry + ( *a - '0' );
        CalculateSumAndCarry( &sum, &carry, currSum );
        result[ idx ] = sum + '0';
        printf("\n %c \n", result[ idx ] );
        idx++;
        a++;
    }   

    while( *a == '\0' && *b != '\0' )
    {   
        unsigned int currSum = carry + ( *b - '0' );
        CalculateSumAndCarry( &sum, &carry, currSum );
        result[ idx ] = sum + '0';
        idx++;
        b++;
    }

    if( carry != 0 )
    {
        result[ idx ] = carry + '0';
        idx++;
    }

    result[ idx ] = '\0';
    reverseString( result );

    return result;
}



