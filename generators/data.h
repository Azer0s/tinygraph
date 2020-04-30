//
// Created by ariel.simulevski on 29.04.20.
//

#ifndef TINYGRAPH_DATA_H
#define TINYGRAPH_DATA_H

namespace tinygraph {
    std::shared_ptr<Vertex> vertex_create(const std::string& name, std::shared_ptr<Type> type);
}

#endif //TINYGRAPH_DATA_H
