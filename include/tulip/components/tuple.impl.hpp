#ifndef TULIP_COMPONENTS_TUPLE_IMPL_HPP
#define TULIP_COMPONENTS_TUPLE_IMPL_HPP

#include <utility> // std::move

namespace tulip {
namespace details {

    template<typename...>
    class tuple_impl;

    template<typename First, typename... Rest>
    class tuple_impl<First, Rest...> {
        First value_;
        tuple_impl<Rest...> rest_;

    public:
        constexpr explicit tuple_impl(First first, Rest... rest) :
            value_(std::move(first)), rest_(std::move(rest)...) {}

        constexpr First const& head() const { return value_; }
        First& head() { return value_; }

        constexpr tuple_impl<Rest...> const& tail() const { return rest_; }
        tuple_impl<Rest...>& tail() { return rest_; }
    };

    template<>
    class tuple_impl<> {
    public:
        constexpr explicit tuple_impl() {}
    };

} // namespace details
} // namespace tulip

#endif // TULIP_COMPONENTS_TUPLE_IMPL_HPP
