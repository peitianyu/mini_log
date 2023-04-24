#include<iostream>
#include <unistd.h>
#include"log.h"

void Test()
{
    for(int i = 0; i < 1e6; i++){
        LOG_FILE_DEBUG("Hello World!\n");
        usleep(100000);
    }
}


int main()
{
    Test();
    return 0;
}