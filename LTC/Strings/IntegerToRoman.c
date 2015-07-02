# include <stdio.h>
# include <stdlib.h>

char map_ones[][5] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
char map_tens[][5] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
char map_hundreds[][5]  = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
char map_thousands[][4] = {"M", "MM", "MMM" };

char* intToRoman(int num)
{
    char *retStr = ( char * )malloc( 16 );
    
    int thousands = num/1000;
    num = num - ( thousands * 1000 ) ;
    
    int hundreds  = num/100;
    num = num - ( hundreds * 100 );
    
    int twos = num/10;
    num = num - ( twos * 10 );
    
    int ones = num;

	printf("\n thousands: %d, hundreds: %d, twos: %d, ones: %d. \n", thousands, hundreds, twos, ones );
    
    unsigned int i = 0;
    
    if( thousands )
    {
        unsigned int j = 0;
        while( map_thousands[ thousands - 1 ][j] != '\0' )
        {
            retStr[ i ] = map_thousands[ thousands - 1 ][ j ];
            i++;
            j++;
        }
    }
    
    if( hundreds )
    {
        unsigned int j = 0;
        while( map_hundreds[ hundreds - 1 ][j] != '\0' )
        {
            retStr[ i ] = map_hundreds[ hundreds - 1 ][ j ];
            i++;
            j++;
        }
    }
    
    if( twos )
    {
        unsigned int j = 0;
        while( map_tens[ twos - 1 ][j] != '\0' )
        {
            retStr[ i ] = map_tens[ twos - 1 ][ j ];
            i++;
            j++;
        }
    }
    
    if( ones )
    {
        unsigned int j = 0;
        while( map_ones[ ones - 1 ][j] != '\0' )
        {
            retStr[ i ] = map_ones[ ones - 1 ][ j ];
            i++;
            j++;
        }
    }
    
    retStr[ i ] = '\0';
    
    return retStr;
}

int main()
{
	printf("\n %s \n", intToRoman( 744 ) );
	return 0;
}
