#include "random-generator.hpp"

using namespace Gsler;

RandomGenerator::RandomGenerator():
    generatorType(gsl_rng_default),
    generator(this->allocate(this->generatorType)),
    min(gsl_rng_min(this->generator)),
    max(gsl_rng_max(this->generator))
{
    // Implicit error checking in allocate()
}

RandomGenerator::RandomGenerator(const GeneratorType *t):
    generatorType(t),
    generator(this->allocate(this->generatorType)),
    min(gsl_rng_min(this->generator)),
    max(gsl_rng_max(this->generator))
{
    // Implicit error checking in allocate()
}

RandomGenerator::RandomGenerator(const RandomGenerator &r):
    generatorType(r.generatorType),
    generator(this->allocate(this->generatorType)),
    min(r.min),
    max(r.max)
{
    // Implicit error checking in allocate()
}

RandomGenerator::~RandomGenerator()
{
    this->free();
}

RandomGenerator::ULong RandomGenerator::getMin() const noexcept(true)
{
    return this->min;
}

RandomGenerator::ULong RandomGenerator::getMax() const noexcept(true)
{
    return this->max;
}

RandomGenerator::ULong RandomGenerator::generate() const noexcept(true)
{
    return gsl_rng_get(this->generator);
}

void RandomGenerator::setupEnvironment()
{
    gsl_rng_env_setup();

    RandomGenerator::checkErrors();
}
