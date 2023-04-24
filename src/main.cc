#include<iostream>
#include <unistd.h>
#include"log.h"


void Test()
{
    for(int i = 0; i < 1e6; i++){
        LOG_DEBUG("Hello World! ", i) << std::endl;
        LOG_INFO("Hello World! ", i) << std::endl;
        LOG_WARN("Hello World! ", i) << std::endl;
        LOG_ERROR("Hello World! ", i) << std::endl;

        usleep(100000);
    }
}


int main()
{
    Test();
    return 0;
}