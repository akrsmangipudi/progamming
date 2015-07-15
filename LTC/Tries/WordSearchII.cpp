# include <iostream>
# include <vector>
# include <string>
# include <stdlib.h>

using namespace std;

class Solution {
public:
	struct TrieNode
    {
        bool isEndOfWord;
		bool isWordUsed;
        struct TrieNode* childPtr[ 26 ];
    };

    /** Initialize your data structure here. */
    struct TrieNode* trieCreate()
    {
        struct TrieNode* root = ( struct TrieNode* )malloc( sizeof( struct TrieNode ) );
    
        root->isEndOfWord = false;
		root->isWordUsed  = false;
    
        int i = 0;
        for( ; i < 26; i++ )
        {
            root->childPtr[ i ] = NULL;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(struct TrieNode* root, const char* word)
    {
        if( !root || ( *word == '\0' ) )
        {
            return;
        }
    
        if( root->childPtr[ *word - 'a' ] )
        {
            if( *(word + 1 ) == '\0' )
            {
                root->childPtr[ *word - 'a' ]->isEndOfWord = true;
				root->childPtr[ *word - 'a' ]->isWordUsed  = false;
                return;
            }       
            insert( root->childPtr[ *word - 'a' ], word + 1 );      
        }
        else
        {
            struct TrieNode* temp = trieCreate();
        
            root->childPtr[ *word - 'a' ] = temp;
        
            if( *(word + 1 ) == '\0' )
            {
                temp->isEndOfWord = true;
				temp->isWordUsed  = false;
                return;
            }
        
            insert( root->childPtr[ *word - 'a' ], word + 1 );
        }
    }

    /** Returns if the word is in the trie. */
    bool search(struct TrieNode* root, const char* word) 
    {
        if( !root || ( *word == '\0' ) )
        {
            return false;
        }
    
        if( !root->childPtr[ *word - 'a' ] )
        {
            return false;
        }
    
        if( *(word + 1 ) == '\0' )
        {
			if( root->childPtr[ *word - 'a' ]->isEndOfWord )
			{
				if( root->childPtr[ *word - 'a' ]->isWordUsed )
				{
					return false;
				}
				else
				{
					root->childPtr[ *word - 'a' ]->isWordUsed = true;
					return true;
				}
			}
			else
			{
            	return false;
			}
        }
    
        return search( root->childPtr[ *word - 'a' ], word + 1 );
    }

    /** Returns if there is any word in the trie 
        that starts with the given prefix. */
    bool startsWith(struct TrieNode* root, const char* prefix)
    {
        if( !root || ( *prefix == '\0' ) )
        {
            return false;
        }
    
        if( !root->childPtr[ *prefix - 'a' ] )
        {
            return false;
        }
    
        if( *(prefix + 1 ) == '\0' )
        {
            return true;
        }
    
        return startsWith( root->childPtr[ *prefix - 'a' ], prefix + 1 );
    }
  	 
    void TryAndPopulateWords( TrieNode* root, vector<string> &words, vector<vector<char> >& board, vector<vector<bool> >& used, string &temp, vector<string> &result, int i_row, int j_col )
    {
        if( i_row < 0 || j_col < 0 || i_row > board.size() - 1 || j_col > board[0].size() - 1 )
        {
            return;
        }

		if( used[ i_row ][ j_col ] )
		{
			return;
		}
        
        temp += board[ i_row ][ j_col ];
        used[ i_row ][ j_col ] = true;
        
		if( startsWith( root, temp.c_str() ) )
        {
            if( search( root, temp.c_str() ) )
            {
                result.push_back( temp );
            }
        }
        else
        {
            used[ i_row ][ j_col ] = false;
        	temp.pop_back();
            return;
        }
        
        TryAndPopulateWords( root, words, board, used, temp, result, i_row - 1, j_col );
        TryAndPopulateWords( root, words, board, used, temp, result, i_row + 1, j_col );
        TryAndPopulateWords( root, words, board, used, temp, result, i_row, j_col - 1 );
        TryAndPopulateWords( root, words, board, used, temp, result, i_row, j_col + 1 );
        
        used[ i_row ][ j_col ] = false;
        temp.pop_back();
    }

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words)
    {
		 struct TrieNode* root = trieCreate();
        
        // Insert all the words into the created trie.
        for( int i = 0; i < words.size(); i++ )
        {
            insert( root, words[ i ].c_str() );
        }

        vector<string> result;
        result.clear();
        
        if( board.size() == 0 || board[0].size() == 0 )
        {
            return result;
        }
        
        vector<vector<bool> > used;
        vector<bool> rowUsed( board[0].size(), false );
        
        for( int i = 0; i < board.size(); i++ )
        {
            used.push_back( rowUsed );
        }
        
        for( int i = 0; i < board.size(); i++ )
        {
            for( int j = 0; j < board[0].size(); j++ )
            {
                    string temp;
                    temp.clear();
                    TryAndPopulateWords( root, words, board, used, temp, result, i, j );
            }
        }
		return result;
    }
};

int main()
{
	Solution s;

	vector< vector<char> > board;
	board.clear();

	vector<char> temp;

	temp.push_back( 'a' );
	temp.push_back( 'a' );
	board.push_back( temp );
	
	vector<string> words;
	words.clear();

	words.push_back("a");
		

#if 0
	temp.clear();
	temp.push_back( 'o' );
	temp.push_back( 'a' );
	temp.push_back( 'a' );
	temp.push_back( 'n' );
	board.push_back( temp );
	

	temp.clear();
	temp.push_back( 'e' );
	temp.push_back( 't' );
	temp.push_back( 'a' );
	temp.push_back( 'e' );
	board.push_back( temp );
	
	temp.clear();
	temp.push_back( 'i' );
	temp.push_back( 'h' );
	temp.push_back( 'k' );
	temp.push_back( 'r' );
	board.push_back( temp );
	
	temp.clear();
	temp.push_back( 'i' );
	temp.push_back( 'f' );
	temp.push_back( 'l' );
	temp.push_back( 'v' );
	board.push_back( temp );

	vector<string> words;
	words.clear();

	words.push_back("oath");
	words.push_back("pea");
	words.push_back("eat");
	words.push_back("rain");
#endif

	vector<string> result = s.findWords( board, words );

	for( unsigned int i = 0; i < result.size(); i++ )
	{
		cout << result[i] << endl;
	}

	return 0;
}
