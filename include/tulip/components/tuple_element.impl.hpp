#ifndef TULIP_COMPONENTS_TUPLE_ELEMENT_IMPL_HPP
#define TULIP_COMPONENTS_TUPLE_ELEMENT_IMPL_HPP

#include "tuple.hpp"

#include <type_traits> // std::add_cv
#include <cstddef> // std::size_t

namespace tulip {
namespace details {

    template<std::size_t, typename>
    struct tuple_element_impl;

    template<std::size_t I, typename T>
    using tuple_element_impl_t = typename tuple_element_impl<I, T>::type;

    // -------------------------------------------------------------------------

    template<std::size_t I, typename First, typename... Rest>
    struct tuple_element_impl<I, tulip::tuple<First, Rest...>>  {
        using type = tuple_element_impl_t<I-1, tulip::tuple<Rest...>>;
    };

    template<typename First, typename... Rest>
    struct tuple_element_impl<0, tulip::tuple<First, Rest...>> {
        using type = First;
    };

    // -------------------------------------------------------------------------

    template<std::size_t I, typename T>
    struct tuple_element_impl<I, const volatile T> {
        using type = typename std::add_cv<tuple_element_impl_t<I, T>>::type;
    };

    template<std::size_t I, typename T>
    struct tuple_element_impl<I, const T> {
        using type = typename std::add_const<tuple_element_impl_t<I, T>>::type;
    };

    template<std::size_t I, typename T>
    struct tuple_element_impl<I, volatile T> {
        using type = typename std::add_volatile<tuple_element_impl_t<I, T>>::type;
    };

} // namespace details
} // namespace tulip

#endif // TULIP_COMPONENTS_TUPLE_ELEMENT_IMPL_HPP
