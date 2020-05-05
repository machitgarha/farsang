#include "random-distribution.hpp"

#include <gsl/gsl_randist.h>

using namespace Gsler;

GaussianDistribution::Double GaussianDistribution::get(Double x) const noexcept
{
    return gsl_ran_gaussian(this->getGenerator().getGenerator(), x);
}
