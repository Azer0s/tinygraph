//
// Created by ariel.simulevski on 29.04.20.
//

#include <memory>
#include <map>
#include <any>
#include "../data/types.h"

namespace tinygraph {
    std::shared_ptr<std::map<std::string, std::any>> vertex_link(std::shared_ptr<Vertex> from, std::shared_ptr<Vertex> to, bool undirected) {
        //TODO: Is this really better tho?
        auto from_cp = std::move(from);

        auto to_edge = std::make_shared<Edge>(std::move(to));
        to_edge->properties = std::make_shared<std::map<std::string, std::any>>();
        from_cp->connections.push_back(to_edge);

        if (undirected) {
            auto from_edge = std::make_shared<Edge>(from_cp);
            from_edge->properties = to_edge->properties;
            to_edge->to->connections.push_back(from_edge);
        }

        return to_edge->properties;
    }
}
