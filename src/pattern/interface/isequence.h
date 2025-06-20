#ifndef REGEX_ISEQUENCE_H
#define REGEX_ISEQUENCE_H

#include "interface.h"

#include <memory>

namespace regex
{
    class ipattern;

    /*
    A sequence of ipattern instances.
    */
    class isequence
    {
        INTERFACE(isequence);

    public:
        /*
        Return the number of elements that this object holds.
        */
        virtual size_t size() const = 0;
        /*
        Add a new element at the end of the list.
        */
        virtual void add(std::unique_ptr<ipattern> pattern) = 0;
        /*
        Remove the element at the specified index.
        */
        virtual void remove_at(const size_t& index) = 0;
        /*
        Remove the element at the back of the list.
        Return the moved unique_ptr that holds the object.
        */
        virtual std::unique_ptr<ipattern> pop_back() = 0;

    protected:
        isequence() = default;
    };

    inline isequence::~isequence() = default;
}

#endif // REGEX_ISEQUENCE_H