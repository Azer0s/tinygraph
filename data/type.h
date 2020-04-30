//
// Created by ariel.simulevski on 29.04.20.
//

#ifndef TINYGRAPH_TYPE_H
#define TINYGRAPH_TYPE_H

#include <string>

namespace tinygraph {
    class Type {
    public:
        std::string name;
        explicit Type(std::string name);
    };
}


#endif //TINYGRAPH_TYPE_H
