#include "random-distribution.hpp"

#include <gsl/gsl_randist.h>

using namespace Gsler;

GammaDistribution::GammaDistribution(const RandomGenerator &rGenerator, A a, B b):
    RandomDistribution(rGenerator)
{
    this->setParamA(a);
    this->setParamB(b);
}

GammaDistribution::Double GammaDistribution::get() const
{
    if (!this->isParamASet || !this->isParamBSet) {
        throw Exception::Exception("Parameter a or b has not been set");
    }

    return gsl_ran_gamma(this->getGenerator().getGenerator(), this->a, this->b);
}

GammaDistribution::Double GammaDistribution::get(A a, B b) const noexcept
{
    return gsl_ran_gamma(this->getGenerator().getGenerator(), a, b);
}
