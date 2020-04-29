//
// Created by ariel.simulevski on 29.04.20.
//

#include <memory>
#include <map>
#include <any>
#include "../data/types.h"

std::shared_ptr<std::map<std::string, std::any>> tinygraph_vertex_link(const std::shared_ptr<Vertex>& from, const std::shared_ptr<Vertex>& to, bool undirected) {
    auto to_edge = std::shared_ptr<Edge>(new Edge(to));
    to_edge->properties = std::shared_ptr<std::map<std::string, std::any>>(new std::map<std::string, std::any>);
    from->connections.push_back(to_edge);

    if (undirected) {
        auto from_edge = std::shared_ptr<Edge>(new Edge(from));
        from_edge->properties = to_edge->properties;
        to->connections.push_back(from_edge);
    }

    return to_edge->properties;
}

