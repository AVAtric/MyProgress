//
// Created by Adnan Vatric on 09.09.2018.
//

#include "stdio.h"
#include "stdlib.h"
#include "progress.h"

#ifdef _WIN32
    #include <windows.h>
	#define wait_time(X) (Sleep(X))
#else
    #include <unistd.h>
    #define wait_time(X) usleep(X*1000)
#endif

#define PROCESS_COUNT 4

int main(void) {
    unsigned int percent = 0;
    unsigned int progress = 0;
    unsigned int sign_nr = 0;

    char signs[4] = {'-', '\\', '|', '/'};

    init_io();

    while(percent < 100) {
#ifdef DEBUG
        wait_key();
#else
        wait_time(50);
#endif

        float sum = 0;
        progress = get_progress();

        for(int i = 0; i < PROCESS_COUNT; i++)
            sum += (progress >> (i * 8)) & 0xFF;

        percent = (unsigned int) ((sum / (255 * PROCESS_COUNT)) * 100);

        progressbar('=', signs[sign_nr], ' ', percent);

        if(sign_nr < 3)
            sign_nr++;
        else
            sign_nr = 0;
    }

    shutdown_io();

    return 0;
}