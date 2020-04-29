//
// Created by ariel.simulevski on 29.04.20.
//

#ifndef TINYGRAPH_TYPE_STORE_H
#define TINYGRAPH_TYPE_STORE_H

void tinygraph_typestore_init();
std::shared_ptr<Type> tinygraph_typestore_add(std::string type);

#endif //TINYGRAPH_TYPE_STORE_H
