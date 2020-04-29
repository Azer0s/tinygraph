//
// Created by ariel.simulevski on 29.04.20.
//

#include <string>
#include <data/type.h>
#include <utility>
#include <map>

std::map<const char*, std::shared_ptr<Type>> types;

void tinygraph_typestore_init() {
    types["none"] = std::shared_ptr<Type>(new Type("none"));
}

std::shared_ptr<Type> tinygraph_typestore_add(std::string type) {
    auto t = std::move(type);
    auto type_obj = std::shared_ptr<Type>(new Type(t));
    types[t.c_str()] = type_obj;

    return type_obj;
}