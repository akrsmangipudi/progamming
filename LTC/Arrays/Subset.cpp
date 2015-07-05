class Solution {
public:

    void PopulateAllCombinations( vector<int> &nums, vector<int>& output, vector<vector<int> > &result, unsigned int currentIdx )
    {
        if( currentIdx < nums.size() )
        {
            for( unsigned int i = currentIdx; i < nums.size(); i++ )
            {
                output.push_back( nums[ i ] );
                
                result.push_back( output );
                
                PopulateAllCombinations( nums, output, result, i + 1 );
                
                output.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        sort( nums.begin(), nums.end() );
        vector<vector< int> > result;
        result.clear();
        
        vector<int> temp;
        temp.clear();
        
        result.push_back( temp );
        
        vector<int> output;
        output.clear();
        
        PopulateAllCombinations( nums, output, result, 0 );
        return result;
    }
};
