#ifndef TULIP_COMPONENTS_TUPLE_SIZE_HPP
#define TULIP_COMPONENTS_TUPLE_SIZE_HPP

#include "tuple_size.impl.hpp"

namespace tulip {

    template<typename Tuple>
    using tuple_size = tulip::details::tuple_size_impl<Tuple>;

} // namespace tulip

#endif // TULIP_COMPONENTS_TUPLE_SIZE_HPP
