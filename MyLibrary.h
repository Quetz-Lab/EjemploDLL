#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>


#ifdef  MyLibrary_EXPORTS
#define MyLibrary_API __declspec(dllexport)
#else
#define MyLibrary_API __declspec(dllexport)
#endif
extern "C"
{
	MyLibrary_API void HelloWorld();
}