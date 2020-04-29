//
// Created by ariel.simulevski on 29.04.20.
//

#include "types.h"
#include <utility>

Edge::Edge(std::shared_ptr<Vertex> vertex) {
    this->to = std::move(vertex);
}
