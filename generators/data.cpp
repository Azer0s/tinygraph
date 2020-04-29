//
// Created by ariel.simulevski on 29.04.20.
//

#include <memory>
#include <utility>
#include <data/types.h>

std::shared_ptr<Vertex> tinygraph_vertex_create(const std::string& name, std::shared_ptr<Type> type) {
    return std::shared_ptr<Vertex>(new Vertex(name, std::move(type)));
}
