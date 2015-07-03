# include <stdio.h>

int compareVersion(char* version1, char* version2)
{
    while( *version1 != '\0' && *version1 == '0' )
    {
        version1++;
    }
    
    while( *version2 != '\0' && *version2 == '0' )
    {
   		version2++;
    }
    return CompareVersions( version1, version2 );
}

int CompareVersions(char* version1, char* version2)
{
    if( *version1 == '\0' && *version2 == '\0' )
    {
       return 0;

    }
    
    if( *version1 == '\0' || *version2 == '\0' )
    {
        if( *version1 == '\0' )
        {
			if( *version2 != '.' )
			{
				return -1;
			}
			else
			{
				version2++;
				while( *version2 != '\0' && ( *version2 == '0' || *version2 == '.' ) )
				{
					version2++;
				}

				if( *version2 == '\0' )
				{
					return 0;
				}
				else
				{
					printf("\n (47)Returning -1 from here. \n" );
					return -1;
				}			
			}
        }
        else
        {
			if( *version1 != '.' )
			{
				return 1;
			}
			else
			{
				version1++;
				while( *version1 != '\0' && ( *version1 == '0' || *version1 == '.' ) )
				{
					version1++;
				}

				if( *version1 == '\0' )
				{
					return 0;
				}
				else
				{
					printf("\n (72)Returning 1 from here. \n" );
					return 1;
				}			
			}
        }
    }
    
    if( *version1 != '\0' && *version2 != '\0' )
    {
        if( *version1 == '.' && *version2 == '.' )
        {
            return CompareVersions( version1 + 1, version2 + 1 );
        }
        else if( *version1 == *version2 )
        {
            return CompareVersions( version1 + 1, version2 + 1 );
        }
        else
        {
			unsigned int one = 0;
			unsigned int two = 0;

			while( *version1 != '\0' && *version1 != '.' )
			{
				one = one * 10 + *version1 - '0';
				version1++;
			}
			
			while( *version2 != '\0' && *version2 != '.' )
			{
				two = two * 10 + *version2 - '0';
				version2++;
			}

			if( one < two )
			{
				printf("\n (108)Returning -1 from here. \n" );
				return -1;
			}
			else if( one > two )
			{
				printf("\n (113)Returning -1 from here. \n" );
				return 1;
			}
			else
			{
				return CompareVersions( version1, version2 );
			}
		}
    }
}

int main()
{
	printf("\n Compare Versions: %d. \n", compareVersion(  "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000", "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000" ));
	return 0;
}
