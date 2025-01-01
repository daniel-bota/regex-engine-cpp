#ifndef INTERFACE_H
#define INTERFACE_H

#define INTERFACE(className)                                \
    /*rule of five*/                                        \
public:                                                     \
    virtual ~className() = 0;                               \
                                                            \
protected:                                                  \
    className(const className& other) = delete;            \
    className(const className&& other) = delete;           \
    className& operator=(const className& other) = delete; \
    className& operator=(const className&& other) = delete;

#endif // INTERFACE_H