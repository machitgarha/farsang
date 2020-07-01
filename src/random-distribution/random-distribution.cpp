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

template<typename ParamType>
ParamType RandomDistribution<ParamType>::getParam() const
{
    if (!this->_isParamSet) {
        throw Exception::Exception("Parameter(s) has(ve) not been set");
    }
    return this->param;
}

template<typename ParamType>
bool RandomDistribution<ParamType>::isParamSet() const noexcept
{
    return this->_isParamSet;
}

template<typename ParamType>
RandomDistribution<ParamType> &RandomDistribution<ParamType>::setParam(ParamType param)
    noexcept
{
    this->_isParamSet = true;
    this->param = param;
    return *this;
}

template<typename ParamType>
const RandomGenerator &RandomDistribution<ParamType>::getGenerator() const noexcept
{
    return this->generator;
}
