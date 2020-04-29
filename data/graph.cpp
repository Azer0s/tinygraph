//
// Created by ariel.simulevski on 29.04.20.
//

#include <tinygraph.h>

#include <utility>
#include <iostream>
#include <sstream>
#include <functions/util.h>
#include "graph.h"

Graph::Graph() = default;

Graph::~Graph() = default;

void Graph::add_vertex(const std::shared_ptr<Vertex>& vertex) {
    this->vertices[vertex->name] = vertex;
}

[[maybe_unused]] std::shared_ptr<Vertex> Graph::get_vertex(const std::string& name) {
    auto v = this->vertices.at(name);
    return v;
}

std::shared_ptr<std::map<std::string, std::any>> Graph::link(const std::string& from, const std::string& to, bool unidirectional) {
    return tinygraph_vertex_link(this->vertices[from], this->vertices[to], unidirectional);
}

std::shared_ptr<Vertex> Graph::add(const std::string &name, std::shared_ptr<Type> type) {
    auto v = tinygraph_vertex_create(name, std::move(type));
    this->add_vertex(v);
    return v;
}

std::string Graph::str() {
    std::string res;

    for (const auto& v : this->vertices) {
        res += v.first;

        for (const auto& p : v.second->properties) {
            res += " [" + p.first + " = " + any_to_str(p.second) + "]";
        }

        res += "\n";

        for (const auto& c : v.second->connections) {
            res += "\t" + v.first + " -> " + c->to->name;

            for (const auto& p : *c->properties) {
                res += " [" + p.first + " = " + any_to_str(p.second) + "]";
            }

            res += "\n";
        }
    }

    return res;
}

std::vector<std::vector<std::string>> Graph::connected_components() {
    //TODO
    this->str();
    return std::vector<std::vector<std::string>>();
}
