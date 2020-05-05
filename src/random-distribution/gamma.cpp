#include "random-distribution.hpp"

#include <gsl/gsl_randist.h>

using namespace Gsler;

GammaDistribution::Double GammaDistribution::get(Double a, Double b) const noexcept
{
    return gsl_ran_gamma(this->getGenerator().getGenerator(), a, b);
}
