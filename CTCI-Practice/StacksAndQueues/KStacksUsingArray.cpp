# include <iostream>

using namespace std;

class KStackArray
{
	int *arr;
	int arraySize;
	int numOfStacks;
	int *top;
	int *next;
	int free;

public:
	KStackArray( int numOfStacks, int arraySize );
	void Push( int element, int sn );
	int  Pop( int sn );

	inline bool IsEmpty( int sn )
	{
		return ( -1 == top[sn] ) ? true : false;		
	}

	inline bool IsFull()
	{
		return ( -1 == free ) ? true : false;
	}
};

KStackArray::KStackArray( int numOfStacks, int arraySize )
{
	this->arraySize    = arraySize;
	this->numOfStacks  = numOfStacks;

	top  = new int[ numOfStacks ];
	for( int i = 0; i < numOfStacks; i++ )
	{
		top[i] = -1;
	}

	arr  = new int[ arraySize ];	

	next = new int[ arraySize ];
	for( int i = 0; i < ( arraySize - 1 ) ; i++ )
	{
		next[i] = i + 1;
	}
	next[ arraySize - 1] = -1;

	free = 0; 
}

void KStackArray::Push( int element, int sn )
{
	if( IsFull( ) )
	{
		cout << "Stack " << sn << " is full." << endl;
		return;
	}

	int i = free;

	free  = next[i];

	next[i] = top[sn];

	top[sn] = i;

	arr[i] = element;
}

int KStackArray::Pop( int sn )
{
	if( IsEmpty( sn ) )
	{
		cout << "Stack " << sn << " is empty." << endl;
		return -1;
	}

	int i = top[sn];

	top[sn] = next[i];

	next[i] = free;

	free = i;

	return arr[i];
}

int main()
{
    int k = 3, n = 10;
    KStackArray ks( k, n );
 
    ks.Push(15, 2);
    ks.Push(45, 2);
 
    ks.Push(17, 1);
    ks.Push(49, 1);
    ks.Push(39, 1);
 
    ks.Push(11, 0);
    ks.Push(9, 0);
    ks.Push(7, 0);
 
    cout << "Popped element from stack 2 is " << ks.Pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.Pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.Pop(0) << endl;
    
	cout << "Popped element from stack 2 is " << ks.Pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.Pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.Pop(0) << endl;
 
	cout << "Popped element from stack 2 is " << ks.Pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.Pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.Pop(0) << endl;
    
	return 0;
}
