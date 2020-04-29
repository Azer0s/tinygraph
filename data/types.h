//
// Created by ariel.simulevski on 29.04.20.
//

#ifndef TINYGRAPH_TYPES_H
#define TINYGRAPH_TYPES_H

#include <string>
#include <memory>
#include <map>
#include <any>
#include <vector>
#include "type.h"

class Edge;

class Vertex {
public:
    Vertex(std::string, std::shared_ptr<Type>);
    ~Vertex();

    void add_prop(const char*, std::any);

    std::string name;
    std::shared_ptr<Type> type;
    std::vector<std::shared_ptr<Edge>> connections;
    std::map<std::string, std::any> properties;
};

class Edge {
public:
    explicit Edge(std::shared_ptr<Vertex>);

    std::shared_ptr<Vertex> to;
    std::shared_ptr<std::map<std::string, std::any>> properties;
};


#endif //TINYGRAPH_TYPES_H
