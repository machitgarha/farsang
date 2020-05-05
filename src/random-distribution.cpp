#include "random-distribution.hpp"

using namespace Gsler;

RandomDistribution::RandomDistribution(const RandomGenerator &rGenerator):
    generator(rGenerator)
{
}

const RandomGenerator &RandomDistribution::getGenerator() const noexcept
{
    return this->generator;
}
