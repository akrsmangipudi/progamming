class Solution {
public:
    bool isPalindrome(int x)
    {
        int  temp = x;
        
        long reversedNum = 0;
        
        if( x < 0 )
        {
            return false;
        }
        
        while( x > 0 )
        {
            reversedNum = ( reversedNum * 10 ) + ( x % 10 );
            x = x/10;
        }
        
        if( reversedNum > INT_MAX )
        {
            return false;   
        }
        else
        {
            if( reversedNum == temp )
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};
