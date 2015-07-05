class Solution
{
public:

    void PopulateAllUniqueCombinations( bool *used, vector<int> &nums, vector<int>& output, vector<vector<int> > &result, unsigned int currentIdx )
    {
        if( currentIdx < nums.size() )
        {
            for( unsigned int i = currentIdx; i < nums.size(); i++ )
            {
                if( ( i != 0 ) && ( nums[ i ] == nums[ i - 1 ] ) && !used[ i - 1 ] ) 
                {
                    continue;
                }
                
                output.push_back( nums[ i ] );
                
                used[ i ] = true;
                
                result.push_back( output );
                
                PopulateAllUniqueCombinations( used, nums, output, result, i + 1 );
                
                output.pop_back();
                
                used[ i ] = false;
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort( nums.begin(), nums.end() );
        vector<vector< int> > result;
        result.clear();
        
        vector<int> temp;
        temp.clear();
        
        result.push_back( temp );
        
        vector<int> output;
        output.clear();
        
        bool used[ nums.size() ];
        memset( used, 0, nums.size() );
        
        PopulateAllUniqueCombinations( used, nums, output, result, 0 );
        return result;
    }
};
