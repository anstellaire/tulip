#ifndef TULIP_COMPONENTS_TIE_IMPL_HPP
#define TULIP_COMPONENTS_TIE_IMPL_HPP

namespace tulip {
namespace details {

    struct ignore_type_impl {
        template<typename T>
        constexpr ignore_type_impl const& operator=(T const&) const { return *this; }
    };

} // namespace details
} // namespace tulip

#endif // TULIP_COMPONENTS_TIE_IMPL_HPP
