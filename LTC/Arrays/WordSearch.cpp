# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:

    bool CheckIfWordExists( vector<vector<char> >& board, vector<vector< bool> > &used, unsigned int level, string word, int i_row, int j_col )
    {
        if( ( i_row < 0 ) || ( i_row > board.size() - 1 ) || ( j_col < 0 ) || ( j_col > board[0].size() - 1 ) )
        {
            return false;
        }
        
        // If current board element is already used, bail out.
        if( true == used[ i_row ][ j_col ] )
        {
            return false;
        }
        
        // If current board character does not match with the one we are looking for, bail out.
        if( board[ i_row ][ j_col ] != word[ level ] )
        {
            return false;
        }
        
        used[ i_row ][ j_col ] = true;
        
        if( level == word.length() - 1 )
        {
            return true;
        }

		bool a = true, b = true, c = true, d = true;

        a = CheckIfWordExists( board, used, level + 1, word, i_row - 1, j_col );
        
		if( !a )
			b = CheckIfWordExists( board, used, level + 1, word, i_row + 1, j_col );

		if( !b )
            c = CheckIfWordExists( board, used, level + 1, word, i_row, j_col - 1 );
        
		if( !c )
   		    d = CheckIfWordExists( board, used, level + 1, word, i_row, j_col + 1 );
               
        used[ i_row ][ j_col ] = false;

		return a || b || c || d;
    }

    bool exist(vector<vector<char> >& board, string word)
    {
        if( word.length() == 0 )
        {
            return false;
        }
        
        // (1) Create a bool vector and populate that into the used vector.
        vector<vector< bool> > used;
        
        vector<bool> temp;
        temp.clear();
        
        for( unsigned int j_col = 0; j_col < board[0].size(); j_col++ )
        {
            temp.push_back( false );
        }
        
        for( unsigned int i_row = 0; i_row < board.size(); i_row++ )
        {
            used.push_back( temp );
        }
        
        for( unsigned int i_row = 0; i_row < board.size(); i_row++ )
        {
            for( unsigned int j_col = 0; j_col < board[0].size(); j_col++ )
            {
                if( board[ i_row ][ j_col ] != word[ 0 ] )
                {
                    continue;
                }
                
                if( true == CheckIfWordExists( board, used, 0, word, i_row, j_col ) )
                {
                    return true;
                }
            }
        }
        
        return false;
        
    }
};

int main()
{
	Solution s;

	vector<vector<char> > board;
	board.clear();

	vector<char> input;
	input.clear();

	input.push_back( 'c' );
	input.push_back( 'a' );
	input.push_back( 'a' );
	board.push_back( input );
	input.clear();

	
	input.push_back( 'a' );
	input.push_back( 'a' );
	input.push_back( 'a' );
	board.push_back( input );
	input.clear();

	input.push_back( 'b' );
	input.push_back( 'c' );
	input.push_back( 'd' );
	board.push_back( input );
	input.clear();
	
	cout << " Exists ? " << s.exist( board, "aab" ) << endl;

	return 0;
}
