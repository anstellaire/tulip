#ifndef TULIP_COMPONENTS_TUPLE_ELEMENT_HPP
#define TULIP_COMPONENTS_TUPLE_ELEMENT_HPP

#include "tuple_element.impl.hpp"

#include <cstddef> // std::size_t

namespace tulip {

    template<std::size_t Idx, typename Tuple>
    using tuple_element = tulip::details::tuple_element_impl<Idx, Tuple>;

    template<std::size_t Idx, typename Tuple>
    using tuple_element_t = typename tuple_element<Idx, Tuple>::type;

} // namespace tulip

#endif // TULIP_COMPONENTS_TUPLE_ELEMENT_HPP
