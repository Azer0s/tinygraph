//
// Created by ariel.simulevski on 29.04.20.
//

#include <memory>
#include <string>
#include <data/type.h>
#include <utility>
#include <map>
#include <memory>

namespace tinygraph {
    std::map<const char*, std::shared_ptr<Type>> types;

    void typestore_init() {
        types["none"] = std::make_shared<Type>("none");
    }

    std::shared_ptr<Type> typestore_add(std::string type) {
        auto type_obj = std::make_shared<Type>(std::move(type));
        types[type_obj->name.c_str()] = type_obj;

        return type_obj;
    }
}
