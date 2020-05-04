//
// Created by ariel.simulevski on 29.04.20.
//

#ifndef TINYGRAPH_CONNECTIONS_H
#define TINYGRAPH_CONNECTIONS_H

namespace tinygraph {
    std::shared_ptr<std::map<std::string, std::any>> vertex_link(std::shared_ptr<Vertex> from, std::shared_ptr<Vertex> to, bool undirected);
}

#endif //TINYGRAPH_CONNECTIONS_H
