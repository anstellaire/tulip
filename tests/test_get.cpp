#include "../include/tulip/tulip.hpp"

#include "utils.hpp"

struct test_empty_tuple {
    void operator()() {
        constexpr tulip::tuple<> t_in{};
        test::is_true<sizeof(t_in) <= 1ul>();
    }
};

struct test_apply_get {
    void operator()() {
        constexpr tulip::tuple<int, float, char> t_in{1, 0.5, 'a'};

        test::is_true<tulip::get<0>(t_in) == 1>();
        test::is_true<tulip::get<1>(t_in) == 0.5>();
        test::is_true<tulip::get<2>(t_in) == 'a'>();
    }
};

int main() {
    test_empty_tuple{}();
    test_apply_get{}();
}
