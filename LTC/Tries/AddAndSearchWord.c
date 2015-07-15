struct WordDictionary
{
    bool isEndOfWord;
    struct WordDictionary* childPtr[ 26 ];
};

/** Initialize your data structure here. */
struct WordDictionary* wordDictionaryCreate()
{
    struct WordDictionary* root = ( struct WordDictionary* )malloc( sizeof( struct WordDictionary ) );
    
    root->isEndOfWord = false;
    
    int i = 0;
    for( ; i < 26; i++ )
    {
        root->childPtr[ i ] = NULL;
    }
}

/** Inserts a word into the data structure. */
void addWord(struct WordDictionary* wordDictionary, char* word)
{
    if( !wordDictionary || ( *word == '\0' ) )
    {
        return;
    }
    
    if( wordDictionary->childPtr[ *word - 'a' ] )
    {
        if( *(word + 1 ) == '\0' )
        {
            wordDictionary->childPtr[ *word - 'a' ]->isEndOfWord = true;
            return;
        }
        
        addWord( wordDictionary->childPtr[ *word - 'a' ], word + 1 );
        
    }
    else
    {
        struct WordDictionary* temp = wordDictionaryCreate();
        
        wordDictionary->childPtr[ *word - 'a' ] = temp;
        
        if( *(word + 1 ) == '\0' )
        {
            temp->isEndOfWord = true;
            return;
        }
        
        addWord( wordDictionary->childPtr[ *word - 'a' ], word + 1 );
    }
}

/** Returns if the word is in the data structure. A word could
    contain the dot character '.' to represent any one letter. */
bool search(struct WordDictionary* wordDictionary, char* word) 
{
    if( !wordDictionary )
    {   
        return false;
    }   
    
    if( *word == '\0' )
    {   
        return wordDictionary->isEndOfWord;
    }   
    
    if( *word == '.' )
    {   
        int i = 0;
        for( ; i < 26; i++ )
        {
            if( wordDictionary->childPtr[ i ] ) 
            {
                if( search( wordDictionary->childPtr[ i ], word + 1 ) ) 
                {
                    return true;
                }
            }
        }
        return false;
    }   
    
    if( !wordDictionary->childPtr[ *word - 'a' ] ) 
    {   
        return false;
    }   
    
    if( *(word + 1 ) == '\0' )
    {   
        return wordDictionary->childPtr[ *word - 'a' ]->isEndOfWord;
    }   
    
    return search( wordDictionary->childPtr[ *word - 'a' ], word + 1 );   
}


/** Deallocates memory previously allocated for the data structure. */
void wordDictionaryFree(struct WordDictionary* wordDictionary) {
    
}

// Your WordDictionary object will be instantiated and called as such:
// struct WordDictionary* wordDictionary = wordDictionaryCreate();
// addWord(wordDictionary, "word");
// search(wordDictionary, "pattern");
// wordDictionaryFree(wordDictionary);
