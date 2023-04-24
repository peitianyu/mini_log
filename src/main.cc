#include<iostream>
#include <unistd.h>
#include"log.h"


void Test()
{
    for(int i = 0; i < 1e6; i++){
        LOG_DEBUG("Hello World! ", i, "\n");
        LOG_INFO("Hello World! ", i, "\n");
        LOG_WARN("Hello World! ", i, "\n");
        LOG_ERROR("Hello World! ", i, "\n");

        usleep(100000);
    }
}


int main()
{
    Test();
    return 0;
}