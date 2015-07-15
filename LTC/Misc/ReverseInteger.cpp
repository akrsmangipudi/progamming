class Solution {
public:

    int reverse(int x)
    {
        long retNum = 0;
        
        bool isInputNeg = false;
        
        if( x < 0 )
        {
            isInputNeg = true;
            x = -x;
        }
        
        while( x > 0 )
        {
            retNum = ( retNum * 10 ) + ( x % 10 );
            x = x/10;
        }
        
        if( isInputNeg )
        {
            retNum = -retNum;
        }
        
        return ( retNum > INT_MAX || retNum < INT_MIN ) ? 0 : retNum;
    }
};
