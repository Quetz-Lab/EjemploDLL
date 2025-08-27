#include "pch.h"
#include "MyLibrary.h"

MyLibrary_API void HelloWorld()
{
    std::cout << "Hola mundo desde dll" << std::endl;
}

MyLibrary_API int Add(int a, int b)
{
    return a + b;
}

MyLibrary_API int Subtract(int a, int b)
{
	return a - b;
}
