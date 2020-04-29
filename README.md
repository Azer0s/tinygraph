## tinygraph

A tiny graph library for C++17

### Examples

```c++
tinygraph_typestore_init();
auto city_type = tinygraph_typestore_add("city");

auto g = std::make_unique<Graph>();

auto vienna = g->add("Vienna", city);
auto berlin = g->add("Berlin", city);
auto paris = g->add("Paris", city);

vienna->add_prop("language_spoken", "german");
berlin->add_prop("language_spoken", "german");
paris->add_prop("language_spoken", "french");

auto v2b_uni = g->link("Vienna", "Berlin", true);
auto v2p_uni = g->link("Vienna", "Paris", true);
auto b2p_uni = g->link("Berlin", "Paris", true);

(*v2b_uni)["distance"] = 685;
(*v2p_uni)["distance"] = 1230;
(*b2p_uni)["distance"] = 1056;
```
