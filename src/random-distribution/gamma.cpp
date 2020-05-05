#include "random-distribution.hpp"

#include <gsl/gsl_randist.h>

using namespace Gsler;

template class Gsler::RandomDistribution<std::tuple<double, double>>;

GammaDistribution::Double GammaDistribution::get() const
{
    // If param is not set, an exception will be thrown by RandomDistribution::getParam()
    return gsl_ran_gamma(this->getGenerator().getGenerator(),
        std::get<0>(this->getParam()), std::get<1>(this->getParam()));
}

GammaDistribution::Double GammaDistribution::get(A a, B b) const noexcept
{
    this->validateParam(std::tuple<A, B>(a, b));
    return gsl_ran_gamma(this->getGenerator().getGenerator(), a, b);
}

GammaDistribution::Double GammaDistribution::get(std::tuple<A, B> t) const noexcept
{
    this->validateParam(t);
    return gsl_ran_gamma(this->getGenerator().getGenerator(),
        std::get<0>(t), std::get<1>(t));
}

void GammaDistribution::validateParam(std::tuple<A, B> t) const
{
    A a = std::get<0>(t);
    B b = std::get<1>(t);
    if (a <= 0 || a == 1) {
        throw Exception::InvalidArgumentException("a must be positive and not equals 1");
    }
    if (b <= 0) {
        throw Exception::InvalidArgumentException("b must be positive");
    }
}

const GammaDistribution &GammaDistribution::operator>>(Double &result) const
{
    result = this->get();
    return *this;
}
