// TestDLLV2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Windows.h>
#include "MyLibrary.h"

//Declaración de función
typedef int(*pfnAdd)(int, int);
typedef int(*pfnSubtract)(int, int);

int sum(int a, int b) {
    return -1;
}

int subtract(int a, int b) {
    return -1;
}

int main()
{
    std::cout << "Hello World!\n";

	std::cout << "Prueba de uso de DLL" << std::endl;

	pfnAdd Add = sum;
	pfnSubtract Subtract = subtract;
	HINSTANCE hGetProcIDDLL = LoadLibrary(L"ejemploDLL.dll");

	if (hGetProcIDDLL != NULL)
	{
		Add = (pfnAdd)GetProcAddress(hGetProcIDDLL, "Add");
		Subtract = (pfnSubtract)GetProcAddress(hGetProcIDDLL, "Subtract");
		if (!Add || !Subtract)
		{
			std::cout << "No se pudieron cargar las funciones." << std::endl;
			return EXIT_FAILURE;
		}
		int a = 5;
		int b = 3;
		std::cout << "Suma: " << Add(a, b) << std::endl;
		std::cout << "Resta: " << Subtract(a, b) << std::endl;
		FreeLibrary(hGetProcIDDLL);
	}
	else
	{
		std::cout << "No se pudo cargar la DLL." << std::endl;
		return EXIT_FAILURE;
	}
	return 0;
}



