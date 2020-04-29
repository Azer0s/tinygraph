cmake_minimum_required(VERSION 3.16)
project(tinygraph)

set(CMAKE_CXX_STANDARD 17)

add_library(tinygraph SHARED tinygraph.h data/graph.cpp data/graph.h data/vertex.cpp generators/data.cpp type/type_store.cpp generators/data.h type/type_store.h data/type.cpp data/type.h data/edge.cpp functions/connections.cpp functions/connections.h data/types.h functions/util.h functions/util.cpp)
target_include_directories (tinygraph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(tinygraph_test test.cpp)
target_link_libraries (tinygraph_test LINK_PUBLIC tinygraph)
