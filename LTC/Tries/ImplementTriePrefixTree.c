# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

struct TrieNode
{
    bool isEndOfWord;
    struct TrieNode* childPtr[ 26 ];
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate()
{
    struct TrieNode* root = ( struct TrieNode* )malloc( sizeof( struct TrieNode ) );
    
    root->isEndOfWord = false;
    
    int i = 0;
    for( ; i < 26; i++ )
    {
        root->childPtr[ i ] = NULL;
    }
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word)
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
            return;
        }
        
        insert( root->childPtr[ *word - 'a' ], word + 1 );
    }
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) 
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
        return root->childPtr[ *word - 'a' ]->isEndOfWord;
    }
    
    return search( root->childPtr[ *word - 'a' ], word + 1 );
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix)
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

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
    
}

int main()
{

	struct TrieNode* root = trieCreate();

	insert(root, "bid");
	insert(root, "ded");
	insert(root, "mqd");
	printf("\n Searching for - pad : %d. \n", search(root, "pad") );
	printf("\n Searching for - bad : %d. \n", search(root, "bad") );
	printf("\n Searching for - .ad : %d. \n", search(root, ".ad") );
	printf("\n Searching for - b.. : %d. \n", search(root, "....") );
//	printf("\n Starts with - hell : %d. \n", startsWith(root, "hell") );
//	printf("\n Starts with - helloa : %d. \n", startsWith(root, "helloa") );
//	printf("\n Starts with - hello : %d. \n", startsWith(root, "hello") );

	return 0;
}
