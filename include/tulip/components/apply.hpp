#ifndef TULIP_TUPLE_APPLY_HPP
#define TULIP_TUPLE_APPLY_HPP

#include "apply.impl.hpp"

#include <type_traits> // std::remove_reference
#include <utility>     // std::forward

namespace tulip {

    template <typename Functor, typename Tuple>
    constexpr auto apply(Functor&& functor, Tuple&& tuple)
        -> decltype(tulip::details::apply_impl(
            std::forward<Functor>(functor), std::forward<Tuple>(tuple),
            tulip::details::enumerate<typename std::remove_reference<Tuple>::type>{}
        )) {

        return tulip::details::apply_impl(
            std::forward<Functor>(functor), std::forward<Tuple>(tuple),
            tulip::details::enumerate<typename std::remove_reference<Tuple>::type>{}
        );
    }

} // namespace tulip

#endif // TULIP_TUPLE_APPLY_HPP
