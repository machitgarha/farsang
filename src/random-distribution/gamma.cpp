#include "random-distribution.hpp"

#include <gsl/gsl_randist.h>

using namespace Gsler;

template class Gsler::RandomDistribution<std::tuple<double, double>>;

GammaDistribution::Double GammaDistribution::get() const
{
    // If param is not set, an exception will be thrown by RandomDistribution::getParam()
    return gsl_ran_gamma(this->getGenerator().getGenerator(),
        std::get<0>(this->getParam()), std::get<1>(this->getParam()));
}

GammaDistribution::Double GammaDistribution::get(A a, B b) const noexcept
{
    return gsl_ran_gamma(this->getGenerator().getGenerator(), a, b);
}

GammaDistribution::Double GammaDistribution::get(std::tuple<A, B> t) const noexcept
{
    return gsl_ran_gamma(this->getGenerator().getGenerator(),
        std::get<0>(t), std::get<1>(t));
}
