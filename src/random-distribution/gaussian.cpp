#include "random-distribution.hpp"

#include <gsl/gsl_randist.h>

using namespace Gsler;

template class Gsler::RandomDistribution<double>;

GaussianDistribution::Double GaussianDistribution::get() const noexcept
{
    return gsl_ran_gaussian(this->getGenerator().getGenerator(), this->getParam());
}

GaussianDistribution::Double GaussianDistribution::get(Double x) const noexcept
{
    return gsl_ran_gaussian(this->getGenerator().getGenerator(), x);
}
