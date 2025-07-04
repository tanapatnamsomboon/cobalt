#include <cobalt/core/core.h>
#include <cobalt/core/log.h>
#include <iostream>

int main()
{
    cobalt::log::init();
    cobalt::init();

    CB_LOG("Hello from cobalt!");

    return 0;
}