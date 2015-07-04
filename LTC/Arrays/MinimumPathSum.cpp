class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        // (1) Populate the first row with the updated sums.
        for( unsigned int i = 1; i < grid[0].size(); i++ )
        {
           grid[ 0 ][ i ] += grid[ 0 ][ i - 1 ];

        }
        
        // (2) Populate the first column with the updated sums.
        for( unsigned int j = 1; j < grid.size(); j++ )
        {
            grid[ j ][ 0 ] += grid[ j - 1 ][ 0 ];
        }
        
        for( unsigned int i_row = 1; i_row < grid.size(); i_row++ )
        {
            for( unsigned int j_col = 1; j_col < grid[ i_row ].size(); j_col++ )
            {
                grid[ i_row ][ j_col ] += min( grid[ i_row - 1 ][ j_col ], grid[ i_row ][ j_col - 1 ] );
            }
        }
        
        return grid[ grid.size() - 1 ][ grid[0].size() - 1 ];
    }
};
