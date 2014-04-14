#pragma once

#include <array>
#include <type_traits>


namespace reflectionzeug
{
    
namespace
{

template <bool Condition, bool... MoreConditions>
struct all;

template <bool... MoreConditions>
struct all<true, MoreConditions...> : public all<MoreConditions...> {};

template <bool... MoreConditions>
struct all<false, MoreConditions...> : public std::false_type {};

template <>
struct all<true> : public std::true_type {};

template <bool Condition>
struct neg : public std::true_type {};

template <>
struct neg<true> : public std::false_type {};

template <typename Type>
struct is_array : public std::false_type {};

template <typename Type, size_t Size>
struct is_array<std::array<Type, Size>> : public std::true_type {};
    
template <typename Type, typename Container>
struct is_special_array : public std::false_type {};
    
template <typename Type, size_t Size>
struct is_special_array<Type, std::array<Type, Size>> : public std::true_type {};
    
}

template <typename Condition>
struct Neg : public neg<Condition::value> {};

template <bool... Conditions>
struct All : public all<Conditions...> {};

template <bool... Conditions>
struct EnableIf : public std::enable_if<All<Conditions...>::value> {};

template <bool... Conditions>
struct DisableIf : public std::enable_if<!All<Conditions...>::value> {};

template <typename Type>
struct isArray : public is_array<Type> {};

template <typename Type>
struct isBoolArray : public is_special_array<bool, Type> {};

template <typename Type>
struct isIntArray : public is_special_array<int, Type> {};

template <typename Type>
struct isDoubleArray : public is_special_array<double, Type> {};

template <typename Type>
struct isUnsignedIntegral : public All<std::is_integral<Type>::value, 
                                       std::is_unsigned<Type>::value, 
                                       Neg<std::is_same<Type, bool>>::value> {};

template <typename Type>
struct isSignedIntegral : public All<std::is_integral<Type>::value, 
                                     std::is_signed<Type>::value, 
                                     Neg<std::is_same<Type, bool>>::value> {};

template <typename Type>
struct isFloatingPoint : public All<std::is_floating_point<Type>::value,
                                    Neg<std::is_same<Type, long double>>::value> {};
    
} // namespace reflectionzeug