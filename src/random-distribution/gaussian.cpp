#include "random-distribution.hpp"

#include <gsl/gsl_randist.h>

using namespace Gsler;

GaussianDistribution::GaussianDistribution(const RandomGenerator &rGenerator, Sigma sigma):
    RandomDistribution(rGenerator),
    sigma(sigma)
{
}

GaussianDistribution::Double GaussianDistribution::get() const noexcept
{
    return gsl_ran_gaussian(this->getGenerator().getGenerator(), this->sigma);
}

GaussianDistribution::Double GaussianDistribution::get(Double x) const noexcept
{
    return gsl_ran_gaussian(this->getGenerator().getGenerator(), x);
}
