#include<iostream>
#include <unistd.h>
#include"log.h"

/*
#define LOG_FILE_DEBUG(...) LOG_FILE("[DEBUG] ", __VA_ARGS__)

#define LOG_FILE_INFO(...) LOG_FILE("[INFO] ", __VA_ARGS__)

#define LOG_FILE_WARN(...) LOG_FILE("[WARN] ", __VA_ARGS__)

#define LOG_FILE_ERROR(...) LOG_FILE("[ERROR] ", __VA_ARGS__)
*/


void Test()
{
    for(int i = 0; i < 1e6; i++){
        LOG_FILE_DEBUG("Hello World! ", i, "\n");
        LOG_FILE_INFO("Hello World! ", i, "\n");
        LOG_FILE_WARN("Hello World! ", i, "\n");
        LOG_FILE_ERROR("Hello World! ", i, "\n");

        usleep(100000);
    }
}


int main()
{
    Test();
    return 0;
}