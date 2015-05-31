# include <stdio.h>
# include <string.h>

int hash[100];

int Find( int k ) 
{
    if( k == 0 || k == 1 ) 
    {   
        return 1;
    }

	if( hash[k] != 0 )
		return hash[k];   

    hash[k] = Find( k - 1 ) + Find( k - 2 );
	return hash[k];
}

int main()
{
	memset( hash, 0, sizeof(hash) );
    printf("\n %d \n", Find( 10 - 1 ) );
    return 0;
}

