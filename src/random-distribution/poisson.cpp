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
    this->validateParam(mu);
    return gsl_ran_poisson(this->getGenerator().getGenerator(), mu);
}

void PoissonDistribution::validateParam(Mu mu) const
{
    if (mu <= 0) {
        throw Exception::InvalidArgumentException("Mu must be positive");
    }
}

const PoissonDistribution &PoissonDistribution::operator>>(UInt &result) const
{
    result = this->get();
    return *this;
}
