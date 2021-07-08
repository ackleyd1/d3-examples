#include <emscripten/val.h>

struct Margin {
    const int top;
    const int right;
    const int bottom;
    const int left;
};

int main() {
    // initializing visualization config
    const int width = 400;
    const int height = 600;
    const std::vector<int> viewBox = {0, 0, height, width};
    const Margin margin = {10, 10, 10, 10};

    // get the data
    const std::vector<double> data =
    {5.1, 4.9, 8.6, 6.2, 5.1, 7.1, 6.7, 6.1, 5, 5, 5.2, 7.9, 11.1, 5.9, 5.5, 5.6, 6.5, 7.7, 5.7, 6.7};

    // get global d3 object
    emscripten::val d3 = emscripten::val::global("d3");

    // separate into bins
    emscripten::val bins = d3
        .call<emscripten::val>("bin")
        .call<emscripten::val, int>("thresholds", 4)(emscripten::val::array(data));

    // scale to viewBox coordinates
    std::vector<int> domain;
    domain.push_back(0);
    domain.push_back(d3.call<int>);

    emscripten::val scaleX = d3
        .call<emscripten::val>("scaleLinear")
        .call<emscripten::val, emscripten::val>("domain", emscripten::val::array())
        .call<emscripten::val>("nice")
        .call<emscripten::val, emscripten::val>("range", emscripten::val::array())

    // create selection from global d3 and append svg
    emscripten::val select = d3
        .call<emscripten::val, std::string>("select", "#target")
        .call<emscripten::val, std::string>("append", "svg")
        .call<emscripten::val, std::string, emscripten::val>("attr", "viewBox", emscripten::val::array(viewBox));

    // create axes

    // bind data to the svg

    // provide callback for graphics
    


    return 0;
}