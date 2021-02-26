# Tulip 🌷

Tulip is a tiny C++11 library that provides [standard-layout](https://en.cppreference.com/w/cpp/named_req/StandardLayoutType) and lite version of `std::tuple`.

The following functionality is implemented:
- `tulip::tuple` (standard-layout version of `std::tuple`)
- `tulip::apply` (analogue of `std::apply` from C++17)
- `tulip::integer_sequence` and derivatives (`make_integer_sequence`, `index_sequence`, etc.)
- `tulip::get`
- `tulip::tie`
- `tulip::tuple_element`
- `tulip::tuple_size`
