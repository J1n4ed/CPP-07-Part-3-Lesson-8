// main function

#include "..\headers\unique_ptr.hpp"
#include <iostream>
#include <Windows.h>

int main(int argc, char** argv)
{
	// CMD SET

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// VARIABLES

	int * ptr = new int;	

	*ptr = 10;

	jinx::unique_ptr<int> ptr_int(ptr);

	// BODY	

	std::cout << "Test: ptr_int = " << *ptr_int << '\n';

	std::cout << "*ptr_int = 15\n";

	*ptr_int = 15;

	std::cout << "Test: ptr_int = " << *ptr_int << '\n';	

	// ptr = nullptr;

	std::cout << "\n*ptr = " << *ptr << ", &ptr = " << &ptr;

	// EXIT

	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;

} // end of MAIN