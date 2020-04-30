//
// Created by ariel.simulevski on 29.04.20.
//

#ifndef TINYGRAPH_GRAPH_H
#define TINYGRAPH_GRAPH_H

#include "types.h"
#include <vector>

namespace tinygraph {
    class Graph {
    public:
        std::map<std::string, std::shared_ptr<Vertex>> vertices;

        Graph();
        ~Graph();

        std::shared_ptr<Vertex> add(const std::string& name, std::shared_ptr<Type> type);

        void add_vertex(std::shared_ptr<Vertex> vertex);

        std::shared_ptr<Vertex> get_vertex(const std::string& name);

        std::shared_ptr<std::map<std::string, std::any>> link(const std::string& from, const std::string& to, bool unidirectional);

        std::vector<std::vector<std::string>> connected_components();

        std::string str();
    };
}

#endif //TINYGRAPH_GRAPH_H
