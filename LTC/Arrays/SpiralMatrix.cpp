class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix)
    {
        vector<int> result;
        result.clear();
        
        if( ( matrix.size() == 0 ) || ( matrix[ 0 ].size() == 0 ) )
        {
            return result;   
        }
        
        int numOfRows = matrix.size();
        int numOfCols = matrix[0].size();
        
        for( int level = 0; level < ( ( min( numOfRows, numOfCols ) + 1 )/2 ); level++ )
        {
            for( int i = level; i < numOfCols - level; i++ )
            {
                result.push_back( matrix[ level ][ i ] );
            }
            
            for( int i = level + 1; i < numOfRows - 1 - level; i++ )
            {
                result.push_back( matrix[ i ][ numOfCols - 1 - level ] );
            }
            
            for( int i = numOfCols - 1 - level; i >= level && ( numOfRows - 1 - level != level ) ; i-- )
            {
                result.push_back( matrix[ numOfRows - 1 - level ][ i ] );
            }
            
            for( int i = numOfRows - 2 - level; i > level && ( numOfCols - 1 - level != level ); i-- )
            {
                result.push_back( matrix[ i ][ level ] );
            }
        }
        
        return result;
    }
};

