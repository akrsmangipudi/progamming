class Solution {
public:
    string convert(string s, int numRows)
    {
        string res;
        res.clear();
        
        if( numRows == 0 || numRows == 1 || s.length() == 0 || numRows >= s.length() )
        {
            return s;
        }
        
        string result[ numRows ];
        
        for( unsigned int i = 0; i < numRows; i++ )
        {
            result[ i ].clear();
        }
        
        unsigned int i = 0;
        unsigned int  currRow = 0;
        unsigned int step = 1;
        while( i < s.length() )
        {
            result[ currRow ] += s[i];
            if( currRow == 0 )
            {
                step = 1;
            }
            else if( currRow == numRows - 1 )
            {
                step = -1;
            }
            currRow = currRow + step;
            i++;
        }
        
        for( unsigned int i = 0; i < numRows; i++ )
        {
            res.append( result[ i ] );
        }
        
        return res;
    }
};
