//
// Created by ariel.simulevski on 29.04.20.
//

#include <tinygraph.h>

#include <utility>
#include <functions/util.h>
#include <algorithm>
#include "graph.h"

namespace tinygraph {
    Graph::Graph() = default;

    Graph::~Graph() = default;

    void Graph::add_vertex(std::shared_ptr<Vertex> vertex) {
        this->vertices[vertex->name] = std::move(vertex);
    }

    std::shared_ptr<Vertex> Graph::get_vertex(const std::string& name) {
        auto v = this->vertices.at(name);
        return v;
    }

    std::shared_ptr<std::map<std::string, std::any>> Graph::link(const std::string& from, const std::string& to, bool unidirectional) {
        return vertex_link(this->vertices[from], this->vertices[to], unidirectional);
    }

    std::shared_ptr<Vertex> Graph::add(const std::string &name, std::shared_ptr<Type> type) {
        auto v = vertex_create(name, std::move(type));
        this->add_vertex(v);
        return v;
    }

    std::string Graph::str() {
        std::string res;

        for (const auto& [key, vertex] : this->vertices) {
            res += key;

            for (const auto& [propKey, property] : vertex->properties) {
                res += " [" + propKey + " = " + any_to_str(&property) + "]";
            }

            res += "\n";

            for (const auto& c : vertex->connections) {
                res += "\t" + key + " -> " + c->to->name;

                for (const auto& [propKey, property] : *c->properties) {
                    res += " [" + propKey + " = " + any_to_str(&property) + "]";
                }

                res += "\n";
            }
        }

        return res;
    }

    void dfs_util(const std::shared_ptr<Vertex>& vertex, const std::shared_ptr<std::map<std::string, bool>>& visited) {
        (*visited)[vertex->name] = true;

        for (const auto& c : vertex->connections) {
            if (!visited->find(c->to->name)->second) {
                dfs_util(c->to, visited);
            }
        }
    }

    std::vector<std::vector<std::string>> Graph::connected_components() {
        auto l = std::vector<Vertex>();
        auto visited = std::shared_ptr<std::map<std::string, bool>>(new std::map<std::string, bool>);

        for (const auto& pair : this->vertices) {
            (*visited)[pair.first] = false;
        }

        dfs_util(this->vertices.begin()->second, visited);
        //TODO
        this->str();
        return std::vector<std::vector<std::string>>();
    }
}