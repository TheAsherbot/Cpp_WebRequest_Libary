#include "HttpRequest.h"

HttpRequest::HttpRequest(const char* url)
{
	this->url = url;
}
HttpRequest::HttpRequest()
{
	url = "";
}
