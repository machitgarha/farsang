#include "random-distribution.hpp"

#include <gsl/gsl_randist.h>

using namespace Farsang;

GaussianDistribution::Double GaussianDistribution::get() const noexcept
{
    // If param is not set, an exception will be thrown by RandomDistribution::getParam()
    return gsl_ran_gaussian(this->getGenerator().getGenerator(), this->getParam());
}

GaussianDistribution::Double GaussianDistribution::get(Sigma sigma) const noexcept
{
    return gsl_ran_gaussian(this->getGenerator().getGenerator(), sigma);
}
