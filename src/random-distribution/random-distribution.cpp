#include "random-distribution.hpp"

using namespace Gsler;

template<typename ParamType>
RandomDistribution<ParamType>::RandomDistribution(const RandomGenerator &rGenerator):
    generator(rGenerator)
{
}

template<typename ParamType>
RandomDistribution<ParamType>::RandomDistribution(const RandomGenerator &rGenerator,
    ParamType param):
    generator(rGenerator),
    param(param)
{
}

template<typename ParamType>
RandomDistribution<ParamType>::~RandomDistribution()
{
}
