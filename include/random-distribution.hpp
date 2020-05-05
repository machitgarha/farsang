#ifndef GSLER_RANDOM_DISTRIBUTION_INC
#define GSLER_RANDOM_DISTRIBUTION_INC

#include <tuple>
#include "random-generator.hpp"
#include "exception.hpp"

namespace Gsler
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
            inline ParamType getParam() const
            {
                if (!this->_isParamSet) {
                    throw Exception::Exception("Parameter(s) has(ve) not been set");
                }
                return this->param;
            }
            inline bool isParamSet() const noexcept
            {
                return this->_isParamSet;
            }
            inline RandomDistribution &setParam(ParamType) noexcept
            {
                this->_isParamSet = true;
                this->param = param;
                return *this;
            }

            virtual inline const RandomGenerator &getGenerator() const noexcept final
            {
                return this->generator;
            }

        private:
            const RandomGenerator &generator;

            bool _isParamSet = false;
            ParamType param;
    };

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
}

#endif // GSLER_RANDOM_DISTRIBUTION_INC
