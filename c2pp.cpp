#include <iostream>
#include <string>
#include <curl/curl.h>

size_t writeCallback(char* ptr, size_t size, size_t nmemb, void* userdata) {
    std::string* response = static_cast<std::string*>(userdata);
    size_t totalSize = size * nmemb;
    response->append(ptr, totalSize);
    return totalSize;
}

int main() {
    std::cout << "[i] Program started\n";
    CURL* curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (curl) {
        std::cout << "[i] CURL initialized\n";

        curl_easy_setopt(curl, CURLOPT_URL, "https://raw.githubusercontent.com/Sparkplugx1904/c2pp-prototype/main/proto.txt");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        std::cout << "[i] Performing request...\n";
        res = curl_easy_perform(curl);
        std::cout << "[i] Request done\n";

        if (res != CURLE_OK) {
            std::cerr << "[!] curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "[✓] Response:\n" << response << std::endl;
        }

        curl_easy_cleanup(curl);
    } else {
        std::cerr << "[!] Failed to initialize curl." << std::endl;
    }

    std::cout << "[i] Program ended\n";
    return 0;
}
// g++ c2pp.cpp -o c2pp.exe -DCURL_STATICLIB -lcurl -lssl -lcrypto -lz -lws2_32 -lbcrypt; if ($?) { ./c2pp.exe }
