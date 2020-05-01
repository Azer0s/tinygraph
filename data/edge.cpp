//
// Created by ariel.simulevski on 29.04.20.
//

#include "types.h"
#include <utility>

namespace tinygraph {
    Edge::Edge(std::shared_ptr<Vertex> vertex) : to(std::move(vertex)) { }
}
