#include "random-generator.hpp"

#include <gsl/gsl_errno.h>

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

RandomGenerator &RandomGenerator::setSeed(const Seed seed)
{
    gsl_rng_set(this->generator, seed);

    RandomGenerator::checkErrors();

    return *this;
}

void RandomGenerator::setupEnvironment()
{
    gsl_rng_env_setup();

    RandomGenerator::checkErrors();
}

void RandomGenerator::free() noexcept(true)
{
    gsl_rng_free(this->generator);
}

void RandomGenerator::checkErrors()
{
    // TODO: Implement this
}

RandomGenerator::Generator *RandomGenerator::allocate(const GeneratorType *t)
{
    Generator *generator = gsl_rng_alloc(t);

    RandomGenerator::checkErrors();

    return generator;
}
