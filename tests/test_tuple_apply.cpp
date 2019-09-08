#include "../include/tulip/tulip.hpp"

#include "utils.hpp"

struct test_apply_wrapper {
    void operator()() {
        tulip::tuple<int, float, char> t_in{1, 0.5, 'a'};
        auto t_out = tulip::apply(wrap{}, t_in);

        using got_type = decltype(t_out);
        using exp_type = tulip::tuple<wrapper<int>, wrapper<float>, wrapper<char>>;
        test::is_same<got_type, exp_type>();
    }
};

struct test_apply_noop {
    void operator()() {
        tulip::tuple<int, float, char> t_in{1, 0.5, 'a'};
        auto t_out = tulip::apply(noop{}, t_in);

        using got_type = decltype(t_out);
        using exp_type = tulip::tuple<int, float, char>;
        test::is_same<got_type, exp_type>();
    }
};

int main() {
    test_apply_wrapper{}();
    test_apply_noop{}();
}
