#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#include<exception>

struct MyAssertException : std::exception
{
    MyAssertException(const char* msg):message(msg){}
    const char* what() const noexcept final {return message;}
    const char* message;
};

bool assert_impl(const char* what);

#define assert(expression) (void)(\
        !(expression) && assert_impl(#expression) \
    )

#endif // MY_ASSERT_H
