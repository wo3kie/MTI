#ifndef _PARAMETRY_WYWOLANIA_H_
#define _PARAMETRY_WYWOLANIA_H_

#include "value.h"

#include <vector>

struct Parameters{
    int argc;
    std::vector< Value*> argv;
};

#endif
