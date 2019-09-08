#ifndef TULIP_COMPONENTS_INTEGER_SEQUENCE_IMPL_HPP
#define TULIP_COMPONENTS_INTEGER_SEQUENCE_IMPL_HPP

#include <cstddef> // std::size_t

namespace tulip {
namespace details {

    template<typename Int, Int... ints>
    struct integer_sequence_impl {
        using value_type = Int;

        constexpr static std::size_t size() noexcept {
            return sizeof...(ints);
        };
    };

    template<typename Int, Int idx, Int max, Int... seq>
    struct make_integer_sequence_impl {
        using type = typename make_integer_sequence_impl<Int, idx+1, max, seq..., idx>::type;
    };

    template<typename Int, Int max, Int... seq>
    struct make_integer_sequence_impl<Int, max, max, seq...> {
        using type = integer_sequence_impl<Int, seq...>;
    };

} // namespace details
} // namespace tulip

#endif // TULIP_COMPONENTS_INTEGER_SEQUENCE_IMPL_HPP
