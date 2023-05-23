#pragma once

#include <iostream>
#include <memory>

/*
Нужно создать упрощённый аналог std::unique_ptr.

В шаблонном классе должны быть реализованы функции:

- Конструктор, принимающий сырой указатель.
- Перегружен оператор * для получения объекта.
- Запрещены оператор присваивания и конструктор копирования.
- Метод release, который освобождает владение и возвращает сырой указатель.
- Деструктор.
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
			_pointer = new T;
			*_pointer = std::move(*obj);
			delete obj;			
		}

		// destructor

		~unique_ptr()
		{
			delete _pointer;
			std::cout << "\nDestructor for unique_ptr called!\n";
		}


	protected:
		// PROTECTED AREA


	private:
		// PRIVATE AREA

		T * _pointer;

	};

} // JINX namespace