#ifndef TULIP_COMPONENTS_INTEGER_SEQUENCE_HPP
#define TULIP_COMPONENTS_INTEGER_SEQUENCE_HPP

#include "integer_sequence.impl.hpp"

#include <cstddef> // std::size_t

namespace tulip {

    template<typename Int, Int... ints>
    using integer_sequence = tulip::details::integer_sequence_impl<Int, ints...>;

    template<typename Int, Int end>
    using make_integer_sequence = typename tulip::details::make_integer_sequence_impl<Int, 0, end>::type;

    template<std::size_t... ints>
    using index_sequence = integer_sequence<std::size_t, ints...>;

    template<std::size_t end>
    using make_index_sequence = make_integer_sequence<std::size_t, end>;

namespace nonstd {

    template<typename Int, Int end, Int beg>
    using make_integer_sequence_from = typename tulip::details::make_integer_sequence_impl<Int, beg, end>::type;

    template<std::size_t end, std::size_t beg>
    using make_index_sequence_from = make_integer_sequence_from<std::size_t, end, beg>;

} // namespace nonstd
} // namespace tulip

#endif // TULIP_COMPONENTS_INTEGER_SEQUENCE_HPP
