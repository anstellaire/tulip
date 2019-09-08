#ifndef TULIP_COMPONENTS_TUPLE_SIZE_IMPL_HPP
#define TULIP_COMPONENTS_TUPLE_SIZE_IMPL_HPP

#include "tuple.hpp"

#include <type_traits> // std::integral_constant
#include <cstddef>     // std::size_t

namespace tulip {
namespace details {

    template<typename>
    struct tuple_size_impl;

    template<typename... Args>
    struct tuple_size_impl<tulip::tuple<Args...>> :
        std::integral_constant<std::size_t, sizeof...(Args)> {};

} // namespace details
} // namespace tulip

#endif // TULIP_COMPONENTS_TUPLE_SIZE_IMPL_HPP
