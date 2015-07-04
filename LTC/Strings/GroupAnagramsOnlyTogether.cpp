# include <iostream>
# include <map>
# include <vector>
# include <algorithm>

using namespace std;

class Solution
{
public:

    unsigned int ComputeHashValue( string &s )
    {
        unsigned int retVal = 0;
        for( unsigned int i = 0; i < s.size(); i++ )
        {
            retVal += s[ i ];
        }
        return retVal;
    }
    
    void GroupAnagramsTogether( vector<string> &strs, vector<string> &result, map< string, pair<unsigned int, bool > > &hashMap )
    {
        for( unsigned int outerIdx = 0; outerIdx < strs.size(); outerIdx++ )
        {
            pair<unsigned int, bool> outer = hashMap[ strs[outerIdx] ];
            
            if( outer.second )
            {
                continue;
            }
            
            bool outerPushed = false;
            
            
            for( unsigned int innerIdx = outerIdx + 1; innerIdx < strs.size(); innerIdx++ )
            {
                pair<unsigned int, bool> inner = hashMap[ strs[innerIdx] ];
            
                // Current string has already been paired, we can bail out here.
                if( inner.second )
                {
                    continue;
                }
                
                // Lengths of the reference string and current string do not match, continue to the next string.
                if( strs[ outerIdx ].length() != strs[ innerIdx ].length() )
                {
                    continue;
                }
                
                // Hash value of the reference string and current string do not match, continue to the next string.
                if( outer.first != inner.first )
                {
                    continue;
                }
                
                // If we are here, the string lengths match and the hash values match.
                // Sort both the strings and check if they are equal.
                
                string one = strs[ outerIdx ];
                string two = strs[ innerIdx ];
                
                sort( one.begin(), one.end() );
                sort( two.begin(), two.end() );
                
                // Strings don't match character by character, continue to the next string.
                if( one.compare( two ) != 0 )
                {
                    continue;
                }
                
                if( !outerPushed )
                {
                    result.push_back( strs[ outerIdx ] );
                    hashMap[ strs[outerIdx] ] = make_pair( outer.first, true );
                    outerPushed = true;
                }
                
                result.push_back( strs[ innerIdx ] );
                
                hashMap[ strs[ innerIdx ] ] = make_pair( inner.first, true );
            }
        }
    }

    vector<string> anagrams(vector<string>& strs)
    {
        vector<string> result;
        result.clear();
        
        if( strs.size() == 0 || strs.size() == 1 )
        {
            return result;
        }
        
        map< string, pair<unsigned int, bool> > hashMap;
        hashMap.clear();
        
        for( unsigned int i = 0; i < strs.size(); i++ )
        {
            hashMap[ strs[i] ] = make_pair( ComputeHashValue( strs[i] ), false );
        }

		pair<unsigned int, bool> p1 = hashMap[ strs[0] ];
		pair<unsigned int, bool> p2 = hashMap[ strs[1] ];

		cout << "p1 = " << p1.first << " " << p1.second << endl;
		cout << "p2 = " << p2.first << " " << p2.second << endl;
        
        GroupAnagramsTogether( strs, result, hashMap );
        
        return result;
    }
};

int main()
{
	Solution s;

	vector<string> input;

	input.push_back("");
	input.push_back("");

	vector<string> result = s.anagrams( input );

	for( unsigned int i = 0; i < result.size(); i++ )
	{
		cout << " Hello " << result[i] << endl;
	}

	return 0;
}
