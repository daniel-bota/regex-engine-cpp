#ifndef _REGEX_FRAMEWORK_MACROS_H
#define _REGEX_FRAMEWORK_MACROS_H

#define INTERFACE(className)                                                   \
    /*rule of five*/                                                           \
public:                                                                        \
    virtual ~className(){};                                                    \
                                                                               \
protected:                                                                     \
    className() = default;                                                     \
    className(const className& other) = delete;                                \
    className(className&& other) = delete;                                     \
    className& operator=(const className& other) = delete;                     \
    className& operator=(className&& other) = delete;

#define NAMESPACE_BEGIN(name)                                                  \
    namespace name                                                             \
    {

#define NAMESPACE_END(name) }

#endif //_REGEX_FRAMEWORK_MACROS_H