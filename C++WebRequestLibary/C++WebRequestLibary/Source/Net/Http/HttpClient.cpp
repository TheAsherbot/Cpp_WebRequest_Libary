#include "HttpClient.h"


HttpClient::HttpClient()
{
	headers = NULL;
	
	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();

    if (!curl)
    {
        std::cerr << "ERROR:\nERROR: CURL DID NOT INIT!\nERROR:\n\n\n";
    }
}

HttpClient::~HttpClient()
{
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

void HttpClient::AddHeader(std::string header, std::string value)
{
	headers = curl_slist_append(headers, (header + ": " + value).c_str());
}

HttpResponse HttpClient::Post(HttpRequest HttpRequest, HttpContent httpContent)
{
    // SETUP
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, HttpRequest.url);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, httpContent.content);

    // RECIVEING THE RESPONSE
    HttpResponse httpResponse;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &httpResponse.content);

    // ERROR CHECKING
    result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
        std::cout << "CURL ERROR: " << curl_easy_strerror(result);
        httpResponse.responseStatus = FAIL;
    }
    else
    {
        httpResponse.responseStatus = OK;
    }

    curl_slist_free_all(headers);

    return httpResponse.content;
}

HttpResponse HttpClient::Get(HttpRequest HttpRequest)
{
    // SETUP
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, HttpRequest.url);

    // RECIVEING THE RESPONSE
    HttpResponse httpResponse;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &httpResponse.content);

    // ERROR CHECKING
    result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
        std::cout << "CURL ERROR: " << curl_easy_strerror(result);
        httpResponse.responseStatus = FAIL;
    }
    else
    {
        httpResponse.responseStatus = OK;
    }

    curl_slist_free_all(headers);

    return httpResponse.content;
}

