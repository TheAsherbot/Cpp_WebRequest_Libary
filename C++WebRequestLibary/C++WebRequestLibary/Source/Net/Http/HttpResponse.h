#pragma once
#include <iostream>


enum ResponseStatus
{
	FAIL = 0,
	OK = 1,
};

class HttpResponse
{
private:
	
public:
	std::string content;
	ResponseStatus responseStatus = FAIL;


	HttpResponse(std::string content, ResponseStatus responseStatus);
	HttpResponse(std::string content);
	HttpResponse(ResponseStatus responseStatus);
	HttpResponse();

};
