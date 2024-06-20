#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "tts.h"

void make_tts_request(const char *api_key, const char *text, const char *output_file) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if (curl) {
        char url[512];
        snprintf(url, sizeof(url), "https://texttospeech.googleapis.com/v1/text:synthesize?key=%s", api_key);

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        char data[1024];
        snprintf(data, sizeof(data), "{\"input\":{\"text\":\"%s\"},\"voice\":{\"languageCode\":\"en-US\",\"name\":\"en-US-Wavenet-D\"},\"audioConfig\":{\"audioEncoding\":\"MP3\"}}", text);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

        FILE *fp = fopen(output_file, "wb");
        if (!fp) {
            fprintf(stderr, "Failed to open output file\n");
            return;
        }
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        
        fclose(fp);
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}
