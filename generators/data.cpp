//
// Created by ariel.simulevski on 29.04.20.
//

#include <memory>
#include <utility>
#include <data/types.h>

namespace tinygraph {
    std::shared_ptr<Vertex> vertex_create(const std::string& name, std::shared_ptr<Type> type) {
        return std::make_shared<Vertex>(name, std::move(type));
    }
}
