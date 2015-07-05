class Solution
{
public:
    
    int CalculateUniquePaths( vector<vector<int>>& obstacleGrid, int maxRows, int maxCols, int currRow, int currCol, map<pair<int,int>, int> &coordinateMap )
    {
        if( currRow == maxRows - 1 || currCol == maxCols - 1 )
        {
            if( currRow == maxRows - 1 )
            {
                unsigned int j_col = currCol;
                for( j_col = currCol; j_col < maxCols; j_col++ )
                {
                    if( obstacleGrid[ currRow ][ j_col ] == 1 )
                    {
                        break;
                    }
                }
                if( j_col == maxCols )
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
                
            }
            else
            {
                unsigned int i_row = currRow;
                for( i_row = currRow; i_row < maxRows; i_row++ )
                {
                    if( obstacleGrid[ i_row ][ currCol ] == 1 )
                    {
                        break;
                    }
                }
                if( i_row == maxRows )
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        
        if( coordinateMap.find( make_pair( currRow, currCol ) ) != coordinateMap.end() )
        {
            return coordinateMap[ make_pair( currRow, currCol) ];
        }
        
        if( obstacleGrid[ currRow ][ currCol ] == 1 )
        {
            coordinateMap[ make_pair( currRow, currCol) ] == 0;
        }
        else
        {
            coordinateMap[ make_pair( currRow, currCol) ] =
                        CalculateUniquePaths( obstacleGrid, maxRows, maxCols, currRow, currCol + 1, coordinateMap ) +
                        CalculateUniquePaths( obstacleGrid, maxRows, maxCols, currRow + 1, currCol, coordinateMap );
        }
                        
        return coordinateMap[ make_pair( currRow, currCol) ];                        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        map<pair<int,int>, int> coordinateMap;
        coordinateMap.clear();
        
        return CalculateUniquePaths( obstacleGrid, obstacleGrid.size(), obstacleGrid[0].size(), 0, 0, coordinateMap );
    }
};
