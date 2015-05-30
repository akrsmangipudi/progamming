# include <stdio.h>

char tees[][9]   = { "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
char teens[][9]  = { "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
char ones[][9]   = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

void PrintWordsForInteger( int inputNum )
{
	int tempNum = inputNum;

	// (1) Calculate the ones digit.
	int one = (inputNum % 10);
	inputNum = (inputNum / 10);

	// (2) Calculate the twos and threes digit.
	int twos = inputNum % 100;
	inputNum = inputNum / 100;

	// (3) Calculate the thousands position.
	int thousands = inputNum % 1000;
	inputNum = inputNum / 1000;

	// (4) Calculate the millions position.
	int millions = inputNum % 1000;
	inputNum = inputNum / 1000;

	// (5) Calculate the billions position.
	int billions = inputNum % 10;
	inputNum = inputNum / 10;

//	printf("\n (1) one: %d, (2) twos: %d, (3): thousands: %d, (4): millions: %d, (5): billions: %d. \n",
//			one, twos, thousands, millions, billions );

	// 'billions' can have a max single digit value.
	if( billions != 0 )
	{
		printf("\n %s billions and ", ones[ (billions - 1 ) ] );
		billions = billions / 10;
	}

	// We can have up to 3 digits millions field.
	if( millions != 0 )
	{
		// 3rd digit present in millions field.
		if( ( millions / 100 ) != 0 )
		{
			printf(" %s hundred ", ones[ (millions/100) - 1 ] ); 
			millions = millions % 100;
		}

		// 2nd digit.
		if( (millions / 10) != 0 )
		{
			// Teens case.
			if( ( millions / 10) == 1 )
			{
				millions = millions % 10;
				if( millions != 0 )
				{
					printf(" %s millions and ", teens[ ( millions - 1 ) ] );
				}
				else // ten
				{
					printf(" %s millions and", "ten" );
				}
				millions = millions / 100;
			}
			else
			{
				printf(" %s", tees[ ( millions/10 - 1) ]);
				millions = millions % 10;
				if( !millions )
					printf(" %s and", "millions" );
			}
		}
		// 3rd digit.
		if( millions != 0 )
		{
			printf(" %s millions and", ones[ ( millions - 1 ) ] );
		}
	}
	
	// We can have up to 3 digits for thousands field.
	if( thousands != 0 )
	{
		// 3rd digit present in thousands field.
		if( ( thousands / 100 ) != 0 )
		{
			printf(" %s hundred ", ones[ (thousands/100) - 1 ] ); 
			thousands = thousands % 100;
		}

		// 2nd digit.
		if( (thousands / 10) != 0 )
		{
			// Teens case.
			if( ( thousands / 10) == 1 )
			{
				thousands = thousands % 10;
				if( thousands != 0 )
				{
					printf(" %s thousands and ", teens[ ( millions - 1 ) ] );
				}
				else // ten
				{
					printf(" %s thousands and ", "ten" );
				}
				thousands = thousands / 100;
			}
			else
			{
				printf(" %s", tees[ ( thousands/10 - 1) ]);
				thousands = thousands % 10;
				if( !thousands )
					printf(" %s and ", "thousands" );
			}
		}
		// 3rd digit.
		if( thousands != 0 )
		{
			printf(" %s thousands and ", ones[ ( thousands - 1 ) ] );
		}
	}

	if( twos != 0 )
	{
		if( ( twos / 10 ) != 0 ) // hundreds digit.
		{
			printf(" %s hundred and ", ones[ (twos/10) - 1 ] );
			twos = twos % 10;
		}

		if( twos )
		{
			if( twos == 1 )
			{
				if( one )
				{
					printf(" %s", teens[ one - 1 ] );
					one = one / 10;
				}
				else // ten
				{
					printf(" %s", "ten" );
				}
			}
			else
			{
				printf(" %s ", tees[ twos - 1] );
			}
			twos = twos / 10;
		}
	}

	if( one )
	{
		printf(" %s and ", ones[ one - 1] );
		one = one/10;
	}

	printf("\n");
}

int main()
{
//	int input = 670000111;

	int input = 710;
	printf("\n InputNumber: %d. \n", input );
	PrintWordsForInteger( input );

	return 0;
}
