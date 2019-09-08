#ifndef TULIP_COMPONENTS_APPLY_IMPL_HPP
#define TULIP_COMPONENTS_APPLY_IMPL_HPP

#include "integer_sequence.hpp"
#include "tuple_size.hpp"
#include "get.hpp"

#include <cstddef> // std::size_t
#include <utility> // std::forward

namespace tulip {
namespace details {

    template<typename Tuple>
    using enumerate = tulip::make_index_sequence<tulip::tuple_size<Tuple>::value>;

    template <typename Functor, typename Tuple, std::size_t... ints>
    constexpr auto apply_impl(Functor&& functor, Tuple&& tuple, tulip::index_sequence<ints...>)
        -> decltype(functor(tulip::get<ints>(std::forward<Tuple>(tuple))...)) {

        return functor(tulip::get<ints>(std::forward<Tuple>(tuple))...);
    }

} // namespace details
} // namespace tulip

#endif // TULIP_COMPONENTS_APPLY_IMPL_HPP
