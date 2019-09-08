#ifndef TULIP_COMPONENTS_GET_IMPL_HPP
#define TULIP_COMPONENTS_GET_IMPL_HPP

#include "tuple_element.hpp"
#include "tuple.hpp"

#include <cstddef> // std::size_t

namespace tulip {
namespace details {

    template<std::size_t I, typename Tuple>
    struct get_impl;

    template<std::size_t I, class First, class... Rest>
    struct get_impl<I, tulip::tuple<First, Rest...>> {

        using tuple_type = tulip::tuple<First, Rest...>;
        using nested_tuple_type = tulip::tuple<Rest...>;
        using tuple_element_type = tulip::tuple_element_t<I, tuple_type>;

        constexpr static tuple_element_type const& get(tuple_type const& t) {
            return get_impl<I-1, nested_tuple_type>::get(t.tail());
        }

        constexpr static tuple_element_type& get(tuple_type& t) {
            return get_impl<I-1, nested_tuple_type>::get(t.tail());
        }
    };

    template<class First, class... Rest>
    struct get_impl<0, tulip::tuple<First, Rest...>> {

        using tuple_type = tulip::tuple<First, Rest...>;
        using tuple_element_type = tulip::tuple_element_t<0, tuple_type>;

        constexpr static tuple_element_type const& get(tuple_type const& t) {
            return t.head();
        }

        constexpr static tuple_element_type& get(tuple_type& t) {
            return t.head();
        }
    };

} // namespace details
} // namespace tulip

#endif // TULIP_COMPONENTS_GET_IMPL_HPP
