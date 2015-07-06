class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        vector<int> result;
        result.clear();
        
        if( nums.size() == 0 || nums.size() == 1 )
        {
            return nums;
        }
        
        if( nums.size() == 2 )
        {
            if( nums[ 0 ] == nums[ 1 ] )
            {
                result.push_back( nums[ 0 ] );
                return result;
            }
            else
            {
                result.push_back( nums[ 0 ] );
                result.push_back( nums[ 1 ] );
                return result;
            }
        }
        
        int count1 = 1, candidate1 = nums[ 0 ];
        
        int idx = 0;
        while( idx < ( nums.size() - 1 ) )
        {
            if( nums[ idx ] != nums[ idx + 1 ] )
            {
                break;
            }
            idx++;
        }
        
        // All elements in the array are unique, it must be the only repeating element.
        if( idx == nums.size() - 1 )
        {
            result.push_back( nums[ 0 ] );
            return result;
        }
        
        count1 = idx + 1;
        
        int count2 = 1;
        int candidate2 = nums[ idx + 1 ];
        
        
        for( unsigned int i = idx + 2; i < nums.size(); i++ )
        {
            if( nums[ i ] == candidate1 )
            {
                count1 += 1;
            }
            else if( nums[ i ] == candidate2 )
            {
                count2 += 1;
            }
            else if( count1 == 0 )
            {
                count1 = 1;
                candidate1 = nums[ i ];
            }
            else if( count2 == 0 )
            {
                count2 = 1;
                candidate2 = nums[ i ];
            }
            else
            {
                count1--;
                count2--;
            }
        }
        
        int c1 = 0, c2 = 0;
        for( unsigned int i = 0; i < nums.size(); i++ )
        {
            if( nums[ i ] == candidate1 )
            {
                c1++;
            }
            
            if( nums[ i ] == candidate2 )
            {
                c2++;
            }
        }
        
        if( c1 > nums.size()/3 )
        {
            result.push_back( candidate1 );
        }
        
        if( c2 > nums.size()/3 )
        {
            result.push_back( candidate2 );
        }
        
        return result;
    }
};
