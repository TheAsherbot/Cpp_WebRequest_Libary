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
    
    httpClient.AddHeader("Authorization", "Bearer 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");
    httpClient.AddHeader("Content-Type", "application/json");
    
    HttpRequest httpRequest(ENDPOINT.c_str());
    std::string content = "{\"model\": \"gpt-3.5-turbo\", \"messages\": [{\"role\": \"system\", \"content\": \"You are a helpful assistant.\"}, {\"role\": \"user\", \"content\": \"How much wood could a wood chuck chuck if a wood chuck could chuck wood? x2 times\"}], \"max_tokens\": 500, \"stream\": true}";
    HttpContent httpContent(content.c_str());
    HttpResponse response = httpClient.Post(httpRequest, httpContent);
    
    httpClient.~HttpClient();
    
    std::cout << "RESPONSE: " + response.content;


    return 0;
}
