#ifndef TULIP_COMPONENTS_TUPLE_HPP
#define TULIP_COMPONENTS_TUPLE_HPP

#include "tuple.impl.hpp"

namespace tulip {

    template<typename... Args>
    using tuple = tulip::details::tuple_impl<Args...>;

} // namespace tulip

#endif // TULIP_COMPONENTS_TUPLE_HPP
