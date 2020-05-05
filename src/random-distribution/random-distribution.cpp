#include "random-distribution.hpp"

using namespace Gsler;

template class Gsler::RandomDistribution<double>;
template class Gsler::RandomDistribution<std::tuple<double, double>>;

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
        throw Exception::Exception("Parameter has not been set");
    }
    return this->param;
}

template<typename ParamType>
bool RandomDistribution<ParamType>::isParamSet() const noexcept
{
    return this->_isParamSet;
}

template<typename ParamType>
RandomDistribution<ParamType> &RandomDistribution<ParamType>::setParam(ParamType p) noexcept
{
    this->param = p;
    return *this;
}

template<typename ParamType>
const RandomGenerator &RandomDistribution<ParamType>::getGenerator() const noexcept
{
    return this->generator;
}
