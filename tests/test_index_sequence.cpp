#include "../include/tulip/tulip.hpp"

#include "utils.hpp"

using namespace tulip;
using namespace nonstd;

template<typename T>
struct test_make_integer_sequence {
    void operator()() {
        test::is_same<make_integer_sequence<T, 0>, integer_sequence<T>>();
        test::is_same<make_integer_sequence<T, 1>, integer_sequence<T, 0>>();
        test::is_same<make_integer_sequence<T, 2>, integer_sequence<T, 0,1>>();
        test::is_same<make_integer_sequence<T, 4>, integer_sequence<T, 0,1,2,3>>();
    }
};

struct test_make_index_sequence {
    void operator()() {
        test::is_same<make_index_sequence<0>, integer_sequence<std::size_t>>();
        test::is_same<make_index_sequence<1>, integer_sequence<std::size_t, 0>>();
        test::is_same<make_index_sequence<2>, integer_sequence<std::size_t, 0,1>>();
        test::is_same<make_index_sequence<4>, integer_sequence<std::size_t, 0,1,2,3>>();
    }
};

template<typename T>
struct test_make_integer_sequence_from {
    void operator()() {
        test::is_same<make_integer_sequence_from<T, 10, 10>, integer_sequence<T>>();
        test::is_same<make_integer_sequence_from<T, 11, 10>, integer_sequence<T, 10>>();
        test::is_same<make_integer_sequence_from<T, 12, 10>, integer_sequence<T, 10,11>>();
        test::is_same<make_integer_sequence_from<T, 14, 10>, integer_sequence<T, 10,11,12,13>>();
    }
};

struct test_make_index_sequence_from {
    void operator()() {
        test::is_same<make_index_sequence_from<10, 10>, integer_sequence<std::size_t>>();
        test::is_same<make_index_sequence_from<11, 10>, integer_sequence<std::size_t, 10>>();
        test::is_same<make_index_sequence_from<12, 10>, integer_sequence<std::size_t, 10,11>>();
        test::is_same<make_index_sequence_from<14, 10>, integer_sequence<std::size_t, 10,11,12,13>>();
    }
};

int main() {
    test_functor<test_make_integer_sequence>::on_types<char, int, long long>();
    test_functor<test_make_integer_sequence_from>::on_types<char, int, long long>();

    test_make_index_sequence{}();
    test_make_index_sequence_from{}();
}
