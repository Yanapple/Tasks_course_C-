#include "my_assert.h"

bool assert_impl(const char* what)
{
    throw MyAssertException(what);
    return true;
}
