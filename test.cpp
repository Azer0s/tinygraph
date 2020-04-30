//
// Created by ariel.simulevski on 29.04.20.
//

#include <iostream>
#include <memory>
#include "tinygraph.h"

static constexpr char DISTANCE[] = "distance";
static constexpr char NAME[] = "name";

void airport_example() {
    auto airport = tinygraph::typestore_add("airport");

    auto g = std::make_unique<tinygraph::Graph>();

    std::shared_ptr<tinygraph::Vertex> v;

    /////////////////
    /// CLUSTER 1 ///
    /////////////////

    v = g->add("PHX", airport);
    v->properties[NAME] = "Phoenix Sky Harbor International Airport";

    v = g->add("BKK", airport);
    v->properties[NAME] = "Suvarnabhumi Airport";

    v = g->add("OKC", airport);
    v->properties[NAME] = "Will Rogers World Airport";

    g->add("JFK", airport);
    v->properties[NAME] = "John F. Kennedy International Airport";

    v = g->add("LAX", airport);
    v->properties[NAME] = "Los Angeles International Airport";

    v = g->add("MEX", airport);
    v->properties[NAME] = "Mexico City International Airport";

    v = g->add("EZE", airport);
    v->properties[NAME] = "Ezeiza International Airport";

    v = g->add("HEL", airport);
    v->properties[NAME] = "Helsinki Airport";

    v = g->add("LOS", airport);
    v->properties[NAME] = "Murtala Muhammed International Airport";

    v = g->add("LIM", airport);
    v->properties[NAME] = "Jorge Chavez International Airport";

    /////////////////
    /// CLUSTER 2 ///
    /////////////////

    v = g->add("LAP", airport);
    v->properties[NAME] = "La Paz International Airport";

    v = g->add("BER", airport);
    v->properties[NAME] = "Berlin Brandenburg International Airport";

    v = g->add("VIE", airport);
    v->properties[NAME] = "Vienna International Airport";

    std::shared_ptr<std::map<std::string, std::any>> linkprops;

    ///////////////////////////////
    /// CLUSTER 1 - Connections ///
    ///////////////////////////////

    linkprops = g->link("PHX", "LAX", true);
    linkprops->insert({DISTANCE, 596});

    linkprops = g->link("PHX", "JFK", true);
    linkprops->insert({DISTANCE, 3465});

    linkprops = g->link("JFK", "OKC", true);
    linkprops->insert({DISTANCE, 2164});

    linkprops = g->link("JFK", "HEL", true);
    linkprops->insert({DISTANCE, 6626});

    linkprops = g->link("JFK", "LOS", true);
    linkprops->insert({DISTANCE, 8449});

    linkprops = g->link("MEX", "LAX", true);
    linkprops->insert({DISTANCE, 2499});

    linkprops = g->link("MEX", "BKK", true);
    linkprops->insert({DISTANCE, 15754});

    linkprops = g->link("MEX", "LIM", true);
    linkprops->insert({DISTANCE, 4231});

    linkprops = g->link("MEX", "EZE", true);
    linkprops->insert({DISTANCE, 7378});

    linkprops = g->link("LIM", "BKK", true);
    linkprops->insert({DISTANCE, 19728});

    ///////////////////////////////
    /// CLUSTER 2 - Connections ///
    ///////////////////////////////

    linkprops = g->link("VIE", "BER", true);
    linkprops->insert({DISTANCE, 522});

    linkprops = g->link("VIE", "LAP", true);
    linkprops->insert({DISTANCE, 10426});

    linkprops = g->link("LAP", "BER", true);
    linkprops->insert({DISTANCE, 9947});

    //g->shortest_path("PHX", "BKK");
    //g->shortest_path_weighed<int>("PHX", "BKK", DISTANCE)

    for (const auto& cluster : g->connected_components()) {
        std::cout << "{ ";
        for (const auto& vertex : cluster) {
            std::cout << vertex << " ";
        }
        std::cout << "}" << std::endl;
    }

    std::cout << g->str();
}

void no_graph_example() {
    auto city = tinygraph::typestore_add("city");

    auto vienna = tinygraph::vertex_create("Vienna", city);
    auto berlin = tinygraph::vertex_create("Berlin", city);
    auto paris = tinygraph::vertex_create("Paris", city);

    vienna->add_prop("language", "german");
    berlin->add_prop("language", "german");
    paris->add_prop("language", "french");

    auto props = tinygraph::vertex_link(vienna, berlin, true);
    props->insert(std::pair<std::string, std::string>("distance", "685 km"));
}

int main() {
    tinygraph::typestore_init();

    no_graph_example();
    airport_example();
}
