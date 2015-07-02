# include <stdio.h>
# include <string.h>
# include <stdbool.h>

bool LessThan( char a, char b )
{
    switch( a )
    {
        case 'I':
            if( b == 'V' || b == 'X' )
            {
                return true;
            }
            else
            {
                return false;
            }
            
        case 'X':
            if( b == 'L' || b == 'C' )
            {
                return true;
            }
            else
            {
                return false;
            }
            
        case 'C':
            if( b == 'D' || b == 'M' )
            {
                return true;
            }
            else
            {
                return false;
            }
            
        default:
                return false;
    }
}


int GetValue( char a )
{
    switch( a )
    {
        case 'I':
            return 1;
            
        case 'V':
            return 5;
            
        case 'X':
            return 10;
            
        case 'L':
            return 50;
            
        case 'C':
            return 100;
            
        case 'D':
            return 500;
            
        case 'M':
            return 1000;
    }
}

int romanToInt(char* s)
{
    int retVal = 0;
    
    while( *s != '\0' )
    {
        if( *(s + 1) != '\0' )
        {
            if( LessThan( *s, *( s + 1 ) ) )
            {
                retVal -= GetValue( *s );   
            }
            else
            {
                retVal += GetValue( *s );
            }
            s++;
        }
        else
        {
            retVal += GetValue( *s );
            s++;
        }
    }
    return retVal;
}

int main()
{
	printf("\n %d \n", romanToInt("MCM"));
	return 0;
}
