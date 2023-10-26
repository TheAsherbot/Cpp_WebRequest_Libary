#include "HttpContent.h"


HttpContent::HttpContent(const char* content)
{
	this->content = content;
}
HttpContent::HttpContent()
{
	content = "";
}
