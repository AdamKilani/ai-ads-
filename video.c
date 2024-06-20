#include <stdio.h>
#include <stdlib.h>
#include "video.h"
#include "tts.h"

void generate_ad(const char *api_key, const char *product_name) {
    char ad_text[512];
    char command[1024];

    snprintf(ad_text, sizeof(ad_text), "Introducing the new %s. Get yours today!", product_name);
    make_tts_request(api_key, ad_text, "output.mp3");

    snprintf(command, sizeof(command), "ffmpeg -f lavfi -i color=c=black:s=1280x720:d=10 -vf \"drawtext=fontfile=/path/to/font.ttf:text='Introducing the %s!':fontcolor=white:fontsize=40:x=(w-text_w)/2:y=(h-text_h)/2\" -c:v libx264 -t 10 -pix_fmt yuv420p video.mp4", product_name);
    system(command);

    snprintf(command, sizeof(command), "ffmpeg -i video.mp4 -i output.mp3 -c:v copy -c:a aac final_ad.mp4");
    system(command);

    printf("Ad created: final_ad.mp4\n");
}
