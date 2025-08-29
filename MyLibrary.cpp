#include "pch.h"
#include "MyLibrary.h"

MyLibrary_API void HelloWorld()
{
    std::cout << "Hola mundo desde dll" << std::endl;
}

MyLibrary_API int HTPPGet(const char* url, WriteCallback callback)
{
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();

    if (curl)
    {
        std::string response;
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        
    }
}

MyLibrary_API int Add(int a, int b)
{
    return a + b;
}

MyLibrary_API int Subtract(int a, int b)
{
	return a - b;
}
