#include "random-distribution.hpp"

#include <gsl/gsl_randist.h>

using namespace Gsler;

template class Gsler::RandomDistribution<double>;

PoissonDistribution::UInt PoissonDistribution::get() const
{
    // If param is not set, an exception will be thrown by RandomDistribution::getParam()
    return gsl_ran_poisson(this->getGenerator().getGenerator(), this->getParam());
}

PoissonDistribution::UInt PoissonDistribution::get(Mu mu) const noexcept
{
    return gsl_ran_poisson(this->getGenerator().getGenerator(), mu);
}
