#pragma once
#define CURL_STATICLIB
#define BUILDING_LIBCURL
#include <iostream>
#include <curl/curl.h>
#include "HttpResponse.h"
#include "HttpRequest.h"
#include "HttpContent.h"


class HttpClient
{

private:
    CURL* curl;
    CURLcode result;
    struct curl_slist* headers;

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) 
    {
        size_t realSize = size * nmemb;
        std::string chunk((char*)contents, realSize);
        std::cout << "Received chunk: " << chunk << std::endl;
        return realSize;
    }

public:
    HttpClient();
	~HttpClient();

    void AddHeader(std::string header, std::string value);

    HttpResponse Post(HttpRequest HttpRequest, HttpContent httpContent);
    HttpResponse Get(HttpRequest HttpRequest);



};
