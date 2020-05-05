#include "random-distribution.hpp"

#include <gsl/gsl_randist.h>

using namespace Gsler;

template class Gsler::RandomDistribution<double>;

GaussianDistribution::Double GaussianDistribution::get() const
{
    // If param is not set, an exception will be thrown by RandomDistribution::getParam()
    return gsl_ran_gaussian(this->getGenerator().getGenerator(), this->getParam());
}

GaussianDistribution::Double GaussianDistribution::get(Sigma sigma) const noexcept
{
    return gsl_ran_gaussian(this->getGenerator().getGenerator(), sigma);
}

const GaussianDistribution &GaussianDistribution::operator>>(Double &result) const
{
    result = this->get();
    return *this;
}
