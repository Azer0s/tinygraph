//
// Created by ariel.simulevski on 29.04.20.
//

#include "type.h"

#include <utility>

namespace tinygraph {
    Type::Type(std::string name) {
        this->name = std::move(name);
    }
}