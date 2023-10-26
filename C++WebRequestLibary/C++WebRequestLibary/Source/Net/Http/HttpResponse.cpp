#include "HttpResponse.h"

HttpResponse::HttpResponse(std::string content, ResponseStatus responseStatus)
{
	this->content = content;
	this->responseStatus = responseStatus;
}
HttpResponse::HttpResponse(std::string content)
{
	this->content = content;
	this->responseStatus = FAIL;
}
HttpResponse::HttpResponse(ResponseStatus responseStatus)
{
	this->content = "";
	this->responseStatus = responseStatus;
}
HttpResponse::HttpResponse()
{
	content = "";
	responseStatus = FAIL;
}
