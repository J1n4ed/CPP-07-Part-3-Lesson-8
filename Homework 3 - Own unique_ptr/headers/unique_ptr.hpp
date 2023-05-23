#pragma once

#include <iostream>
#include <memory>

/*
����� ������� ���������� ������ std::unique_ptr.

� ��������� ������ ������ ���� ����������� �������:

- �����������, ����������� ����� ���������.
- ���������� �������� * ��� ��������� �������.
- ��������� �������� ������������ � ����������� �����������.
- ����� release, ������� ����������� �������� � ���������� ����� ���������.
- ����������.
*/

namespace jinx
{

	template<class T>
	class unique_ptr
	{
	public:
		// PUBLIC AREA

		// public methods

		T & release()
		{
			T * ret = _pointer;
			delete [] _pointer;
			_pointer = nullptr;
			return ret;
		}

		// overloads

		T & operator*()
		{
			return *_pointer;
		}

		unique_ptr<T> operator=(const unique_ptr<T> & obj) = delete;

		// constructor

		unique_ptr() = delete;
		unique_ptr(const unique_ptr<T> & obj) = delete;

		unique_ptr(T * obj)
		{
			// extra verbose for test
			// verb
			std::cout << '\n' << "> Constructor for unique ptr!\n";
			std::cout << "> *obj = " << *obj << ", &obj = " << &obj << '\n';

			_pointer = new T;
			*_pointer = std::move(*obj);

			// verb
			std::cout << "> *_pointer = " << *_pointer << ", &_pointer = " << &_pointer << '\n';
			std::cout << std::endl;

			delete obj;			
		}

		// destructor

		~unique_ptr()
		{
			delete _pointer;
			std::cout << "\n> Destructor for unique_ptr called!\n";
		}


	protected:
		// PROTECTED AREA


	private:
		// PRIVATE AREA

		T * _pointer;

	};

} // JINX namespace