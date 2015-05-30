# include <iostream>

using namespace std;

class Building
{
	unsigned int area;
	unsigned int floors;

	unsigned int TestVariable;

public:

	Building()
	{
		area = 0;
		floors = 0;
		TestVariable = -1;
	}

	// Getter and Setter methods for the area of a building.
	void SetArea( unsigned int area );
	unsigned int GetArea();

	// Getter and Setter methods for the floors in a building.
	void SetFloors( unsigned int floors );
	unsigned int GetFloors();	
};

void Building::SetArea( unsigned int area )
{
	TestVariable = 10000;
	this->area = area;
}

unsigned int Building::GetArea()
{
	cout << " TestVariable: " << TestVariable<< endl;
	return this->area;
}

void Building::SetFloors( unsigned int floors )
{
	this->floors = floors;
}

unsigned int Building::GetFloors()
{
	return this->floors;
}

class House : public Building
{
public:
	int bedrooms;
	int bathrooms;
	int floors;

public:

	House()
	{
		bedrooms  = 0;
		bathrooms = 0;
	//	floors = 0;
	}

	void SetBedrooms( unsigned int bedrooms );
	unsigned int GetBedrooms();

	void SetBathrooms( unsigned int bathrooms );
	unsigned int GetBathrooms();
	
#if 0
	void SetFloors( unsigned int floors )
	{
		this->floors = floors;
	}

	unsigned int GetFloors()
	{
		return this->floors;
	}
#endif
};

void House::SetBedrooms( unsigned int bedrooms )
{
	this->bedrooms = bedrooms;
}

unsigned int House::GetBedrooms()
{
	return this->bedrooms;
}

void House::SetBathrooms( unsigned int bathrooms )
{
	this->bathrooms = bathrooms;
}

unsigned int House::GetBathrooms()
{
	return this->bathrooms;
}

int main()
{
	Building b;
	House h;

	cout << " Size of building object: " << sizeof(b) << " and size of house object: " << sizeof(h) << " ." << endl;

	b.SetFloors( 10 );
	h.SetFloors( 20 );
	cout << "Number of floors: " << b.GetFloors() << endl;
	cout << "Number of floors: " << h.GetFloors() << endl;

#if 0
	b.SetArea( 1000 );
	b.SetFloors( 10 );

//	h.SetArea( 1000 );
	h.SetBedrooms( 4 );
	h.SetBathrooms( 3 );

	cout << " ****** Base-class ****** " << endl;
	cout << "Area: " << b.GetArea() << endl;
	cout << "Number of floors: " << b.GetFloors() << endl;

//	b.TestFunction();

	cout << " ****** Sub-class ****** " << endl;

	cout << "Number of bedrooms: " << h.GetBedrooms() << endl;
	cout << "Number of bathrooms: " << h.GetBathrooms() << endl;
	
	cout << "Area: " << h.GetArea() << endl;
	cout << "Floors: " << h.GetFloors() << endl;
#endif

	return 0;
}
