#pragma once

#include <iostream>

#include "emp/base/vector.hpp"
#include "emp/data/DataFile.hpp"
#include "emp/math/Random.hpp"
#include "emp/math/random_utils.hpp"

#include "fitness.hpp"
#include "selection.hpp"


void evolve() {
  const size_t population_size = 50;
  const size_t gens = 100;
  size_t curr_gen = 0;

    // make random engine
  emp::Random rand(-1);

  // vector to store our population,
  // fill it with randomized genomes between 0 and 1
  emp::vector<double> population;
  population = emp::RandomDoubleVector(
    rand,
    population_size,
    0.0,
    1.0
  );

}

int main()
{
   
}