//
// Created by ariel.simulevski on 29.04.20.
//

#ifndef TINYGRAPH_CONNECTIONS_H
#define TINYGRAPH_CONNECTIONS_H

std::shared_ptr<std::map<std::string, std::any>> tinygraph_vertex_link(const std::shared_ptr<Vertex>& from, const std::shared_ptr<Vertex>& to, bool undirected);

#endif //TINYGRAPH_CONNECTIONS_H
