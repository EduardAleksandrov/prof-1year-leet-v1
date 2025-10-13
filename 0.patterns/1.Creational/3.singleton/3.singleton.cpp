/*
    Singleton
    Одиночка
*/
# include <iostream>
# include <memory>

using namespace std;

class Sun
{
public:
	static shared_ptr<Sun> instance()
	{
		class SunProxy : public Sun {};

		static shared_ptr<Sun> myInstance = make_shared<SunProxy>();

		return myInstance;
	}
	
	~Sun() 
	{ 
		cout << "Calling the destructor;" << endl; 
	}

	void shine() 
	{ 
        x++;
		cout << "The sun is shining;" << x << endl; 
	}

	Sun(const Sun&) = delete;
	Sun& operator =(const Sun&) = delete;

private:
	Sun() 
	{ 
		cout << "Calling the default constructor;" << endl; 
	}

    int x;
};

int main()
{
	shared_ptr<Sun> sun(Sun::instance());

	sun->shine();
    sun->shine();
}