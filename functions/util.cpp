//
// Created by ariel.simulevski on 29.04.20.
//

#include <string>
#include <any>

namespace tinygraph {
    std::string any_to_str(const std::any* val) {
        if (val->type() == typeid(int)) {
            return std::to_string(std::any_cast<int>(*val));
        } else if (val->type() == typeid(std::string)) {
            return std::any_cast<std::string>(*val);
        } else if (val->type() == typeid(float)) {
            return std::to_string(std::any_cast<float>(*val));
        } else if (val->type() == typeid(const char*)) {
            return std::any_cast<const char*>(*val);
        } else {
            return "<value>";
        }
    }
}
