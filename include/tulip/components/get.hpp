#ifndef TULIP_COMPONENTS_GET_HPP
#define TULIP_COMPONENTS_GET_HPP

#include "get.impl.hpp"
#include "tuple_element.hpp"
#include "tuple.hpp"

#include <cstddef> // std::size_t

namespace tulip {

    template<std::size_t I, typename... Types>
    constexpr tulip::tuple_element_t<I, tulip::tuple<Types...>> const& get(tulip::tuple<Types...> const& t) {
        return tulip::details::get_impl<I, tulip::tuple<Types...>>::get(t);
    };

    template<std::size_t I, typename... Types>
    constexpr tulip::tuple_element_t<I, tulip::tuple<Types...>>& get(tulip::tuple<Types...>& t) {
        return tulip::details::get_impl<I, tulip::tuple<Types...>>::get(t);
    };

} // namespace tulip

#endif // TULIP_COMPONENTS_GET_HPP
