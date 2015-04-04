
#pragma once


#include <reflectionzeug/new/TypedBase.h>


namespace reflectionzeug
{


/**
*  @brief
*    Implementation for signed integral types
*/
template <typename T, typename Accessor>
class TypedSignedIntegral : public TypedBase<T, Accessor>
{
public:
    TypedSignedIntegral(const Accessor & accessor);
    virtual ~TypedSignedIntegral();

    virtual long long toLongLong() const;
    virtual bool fromLongLong(long long value);
};


} // namespace reflectionzeug


#include <reflectionzeug/new/TypedSignedIntegral.hpp>
