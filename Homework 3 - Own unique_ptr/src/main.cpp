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

	std::cout << "*ptr = " << *ptr << ", &ptr = " << &ptr << '\n';

	jinx::unique_ptr<int> ptr_int(ptr);

	std::cout << "jinx::unique_ptr<int> ptr_int(ptr);" << '\n';

	// BODY	

	std::cout << "*ptr_int = " << *ptr_int << ", &ptr_int = " << &ptr_int << '\n';

	std::cout << "\nИзменяем значение, *ptr_int = 15\n\n";

	*ptr_int = 15;

	std::cout << "*ptr_int = " << *ptr_int << ", &ptr_int = " << &ptr_int << '\n';

	// ptr = nullptr;

	std::cout << "\n*ptr = " << *ptr << ", &ptr = " << &ptr << '\n';

	{
		// extra test
		double* ptr_d = new double(3.14);
		jinx::unique_ptr<double> uptr_dbl(ptr_d);

		std::cout << "\n*uptr_dbl = " << *uptr_dbl << '\n';

		*uptr_dbl = 2.17;

		std::cout << "\n*uptr_dbl = " << *uptr_dbl << '\n';
	}

	// EXIT

	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;

} // end of MAIN