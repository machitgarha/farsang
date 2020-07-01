#ifndef FARSANG_RANDOM_DISTRIBUTION_INC
#define FARSANG_RANDOM_DISTRIBUTION_INC

#include <tuple>
#include "random-generator.hpp"
#include "exception.hpp"

namespace Farsang
{
    template<typename ParamType>
    class RandomDistribution
    {
        public:
            using ParamName = std::string;
            using Double = double;
            using UInt = unsigned int;

            RandomDistribution() = delete;
            RandomDistribution(const RandomGenerator &);
            RandomDistribution(const RandomGenerator &, ParamType);

            // Only for making class abstract
            virtual ~RandomDistribution() = 0;

            // Parameter handling
            ParamType getParam() const;
            bool isParamSet() const noexcept;
            RandomDistribution &setParam(ParamType) noexcept;

            virtual const RandomGenerator &getGenerator() const noexcept final;

        private:
            const RandomGenerator &generator;

            bool _isParamSet = false;
            ParamType param;
    };

    // Explicit instantiations
    template class Farsang::RandomDistribution<double>;
    template class Farsang::RandomDistribution<std::tuple<double, double>>;

    class GaussianDistribution: public RandomDistribution<double>
    {
        public:
            using Sigma = Double;

            GaussianDistribution() = delete;
            using RandomDistribution::RandomDistribution;

            // Uses default sigma
            virtual Double get() const noexcept final;
            virtual Double get(Sigma) const noexcept final;
    };

    class PoissonDistribution: public RandomDistribution<double>
    {
        public:
            using Mu = Double;

            PoissonDistribution() = delete;
            using RandomDistribution::RandomDistribution;

            // Uses default Mu
            virtual UInt get() const final;
            virtual UInt get(Mu) const noexcept final;
    };

    class GammaDistribution: public RandomDistribution<std::tuple<double, double>>
    {
        public:
            using A = Double;
            using B = Double;

            GammaDistribution() = delete;
            using RandomDistribution::RandomDistribution;

            // Uses default a and b
            virtual Double get() const final;
            virtual Double get(A, B) const noexcept final;
            virtual Double get(std::tuple<A, B>) const noexcept final;
    };
}

#endif // FARSANG_RANDOM_DISTRIBUTION_INC
