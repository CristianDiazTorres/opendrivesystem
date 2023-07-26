#pragma once

#include "Common/Internal/Internal.h"
#include <assert.h>

#define _NCM_DEFAULT_INSTANCE_DECLARE(type, retTypeSymbol, retParamSymbol) \
protected: \
    static type* defaultInstance; \
 \
public: \
    static void createDefaultInstance() \
    { \
        assert(defaultInstance == 0); \
        defaultInstance = new type(); \
    } \
 \
    static type retTypeSymbol getDefaultInstance() \
    { \
        return retParamSymbol defaultInstance; \
    } \

#define _NCM_DEFAULT_INSTANCE_INIT_DECLARE(type, retTypeSymbol, retParamSymbol) \
    _NCM_DEFAULT_INSTANCE_DECLARE(type, retTypeSymbol, retParamSymbol) \
    static void initDefaultInstance() \
    { \
        defaultInstance->init(); \
    } \

namespace _NCM
{


}
