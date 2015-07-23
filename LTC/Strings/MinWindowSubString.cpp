# include <iostream>
# include <string>
# include <map>

using namespace std;

class Solution {
public:

    bool BothMapsMatch( map<char, int>& sMap, map<char, int>& tMap)
    {
        for( map<char, int>::iterator it = tMap.begin(); it != tMap.end(); it++ )
        {
            // If the key from the TMap does not exist in SMap, bail out.
            if( sMap.find( it->first ) == sMap.end() )
            {
                return false;
            }
            
            // If the value for this key in the SMap is less than the TMap value, we still need to broaden our window and retry, so bail out.
            if( sMap[ it->first ] < it->second )
            {
                return false;
            }
        }
        
        return true;
    }
    
    bool CompareMaps( map<char, int>& sMap, map<char, int>& tMap, char removeChar )
    {
        // Current char does not even exist in the map, so let's bail out as it is safe to let go of this character.
        if( sMap.find( removeChar ) == sMap.end() )
        {
            return true;
        }
        
        if( sMap[ removeChar ] > tMap[ removeChar ] )
        {
            return true;
        }
        
        return false;
    }

    string minWindow(string s, string t) 
    {
        if( s.length() == 0 || t.length() == 0 )
        {
            return "";
        }
        
        // (1) Construct the map for the string T.
        map<char, int> tMap;
        tMap.clear();
        
        for( int i = 0; i < t.length(); i++ )
        {
            if( tMap.find( t[ i ] ) == tMap.end() )
            {
                tMap[ t[ i ] ] = 1;
            }
            else
            {
                tMap[ t[ i ] ] += 1;
            }
        }
        
        // (2) Construct the map for string S, and simultaneously check if there is any possibility of returning a substring from S such that it encloses                all the characters from the string T.
        map<char, int> sMap;
        sMap.clear();
        
        int currentStart = -1;
        int currentEnd   = -1;
        
        int i = 0;
        while( i < s.length() )
        {
            if( tMap.find( s[ i ] ) != tMap.end() )
            {
                currentStart = i;
                break;
            }
            i++;
        }
        
        // No character from string T has been found in string S, so return empty string, otherwise, we would have a valid start index position.
        if( !( i < s.length() ) )
        {
            return "";
        }
        
        for( int i = currentStart; i < s.length(); i++ )
        {
            if( tMap.find( s[ i ] ) != tMap.end() )
            {
                sMap[ s[ i ] ] += 1;
                
                // Check if we found an initial starting string span such that our string S now contains all the characters from String T.
                if( BothMapsMatch( sMap, tMap ) )
                {
                    currentEnd = i;
                    break;
                }
            }
        }
        
        // We found the starting position, we were not able to find the ending position in the String S, such that it encompasses all the characters                  present in the string T.
        if( currentEnd == - 1 )
        {
            return "";
        }

        // We finally found a working window in S that has all the characters that we are looking for in the string T, so update the result string.
        string result; result.clear();
        result = s.substr( currentStart, currentEnd - currentStart + 1 );
			
        // This the best possible combination, return it without undergoing further hassle.
        if( result.length() == t.length() )
        {
            return result;
        }

        // Now, our aim is to find a shorter window than the current window which still includes all characters from the string S in string T.
		while( 1 )
		{
            // Get the left most character in the current window that we are planning on letting go.
            char removeChar = s[ currentStart ];
            
			// As long as removing characters from the left window does no harm to the combination, keep removing characters from the left side to shorten the window.
            while( CompareMaps( sMap, tMap, removeChar ) )
            {
                // If current char exists in the SMap, decrement the count first.
                if( sMap.find(removeChar) != sMap.end() )
                {
                    sMap[ removeChar ] -= 1;
                }
                
                currentStart++;
                removeChar = s[ currentStart ];
				string temp = s.substr( currentStart, currentEnd - currentStart + 1 );

				if( temp.length() < result.length() )
				{
					result = temp;
				}
            }
            
			// At this step, we are pointing to the character if removed from the left side, needs to be included from the right side.
			if( currentEnd  < s.length() - 1 )
			{
				currentEnd++;

				if( sMap.find( s[ currentEnd ] ) != sMap.end() )
				{
					sMap[ s[ currentEnd ] ] += 1;

					// Check if the currentEnd is pointing to the character that needs to be removed from the left side.
					if( s[ currentEnd ] == removeChar )
					{
						while( CompareMaps( sMap, tMap, s[ currentStart ] ) )
						{
							if( sMap.find( s[ currentStart] ) != sMap.end() )
							{
								sMap[ s[ currentStart ] ] -= 1;							
							}
							currentStart++;
						}
					}
				}

				string temp = s.substr( currentStart, currentEnd - currentStart + 1 );

        	    if( temp.length() < result.length() )
	            {
            	    result = temp;
    	        }
			}
			else
			{
				break;
			}
		}
		
        return result;
    }
};

int main()
{
	Solution s;

	string result = s.minWindow( "bbaac", "aba" );

	cout << " Result = " << result << "." << endl;

	return 0;
}
