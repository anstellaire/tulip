#ifndef TULIP_COMPONENTS_TIE_HPP
#define TULIP_COMPONENTS_TIE_HPP

#include "tie.impl.hpp"
#include "tuple.hpp"

namespace tulip {

    using ignore_type = tulip::details::ignore_type_impl;

    static constexpr ignore_type ignore;

    template<typename... Args>
    constexpr tulip::tuple<Args&...> tie(Args&... args) noexcept {
        return tulip::tuple<Args&...>(args...);
    }

} // namespace tulip

#endif // TULIP_COMPONENTS_TIE_HPP
