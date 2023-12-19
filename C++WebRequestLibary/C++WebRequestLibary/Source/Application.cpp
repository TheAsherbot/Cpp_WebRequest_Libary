#include <iostream>
#include <chrono>
#include <string>
#include <curl/curl.h>

#include "net/Http/HttpClient.h"

// OpenAI API endpoint
const std::string ENDPOINT = "https://api.openai.com/v1/chat/completions";

int main() {
    
    // Test();

    HttpClient httpClient;
    
    httpClient.AddHeader("Authorization", "Bearer ");
    httpClient.AddHeader("Content-Type", "application/json");
    
    HttpRequest httpRequest(ENDPOINT.c_str());
    std::string content = "";
    HttpContent httpContent(content.c_str());
    HttpResponse response = httpClient.Post(httpRequest, httpContent);
    
    httpClient.~HttpClient();
    
    std::cout << "RESPONSE: " + response.content;


    return 0;
}
