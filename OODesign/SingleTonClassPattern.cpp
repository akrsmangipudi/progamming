# include <iostream>

using namespace std;

class SingletonDemo
{
	SingletonDemo() { }
	static SingletonDemo *ptr;

public:
	static SingletonDemo* GetSingletonInstance()
	{
		if( ptr )
		{
			return ptr;
		}
		else
		{
			ptr = new SingletonDemo;
			return ptr;
		}
	}

	void Method1()
	{
		cout << " Hello from Method1." << endl;
	}

	void Method2()
	{
		cout << " Hello from Method2." << endl;
	}
};


SingletonDemo* SingletonDemo::ptr = NULL;

int main()
{
	SingletonDemo::GetSingletonInstance()->Method1();
	SingletonDemo::GetSingletonInstance()->Method2();

	return 0;
}
