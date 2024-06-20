#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tts.h"
#include "video.h"

int main() {
    const char *api_key = "YOUR_GOOGLE_API_KEY";
    const char *product_name = "Amazing Widget";

    generate_ad(api_key, product_name);

    return 0;
}
