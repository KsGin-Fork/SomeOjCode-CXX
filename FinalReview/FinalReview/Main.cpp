#include <iostream>
#include <string>

int main(int argc , char* argv[])
{
	std::cout << 
		[]()->std::string
	    {
		    return "!!";
	    }()
	<< std::endl;
	system("Pause");
}