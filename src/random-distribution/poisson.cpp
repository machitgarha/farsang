#include "random-distribution.hpp"

#include <gsl/gsl_randist.h>

using namespace Gsler;

PoissonDistribution::UInt PoissonDistribution::get(Double mu) const noexcept
{
    return gsl_ran_poisson(this->getGenerator().getGenerator(), mu);
}
