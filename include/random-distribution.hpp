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
            RandomDistribution(const RandomGenerator &rGenerator):
                generator(rGenerator)
            {
            }
            RandomDistribution(const RandomGenerator &rGenerator, ParamType param):
                generator(rGenerator),
                param(param)
            {
            }

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
            inline RandomDistribution &setParam(ParamType param) noexcept
            {
                this->validateParam(param);
                this->_isParamSet = true;
                this->param = param;
                return *this;
            }

            virtual void validateParam(ParamType) const = 0;

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
            virtual Double get() const final;
            virtual Double get(Sigma) const noexcept final;

            virtual void validateParam(Sigma) const override;

            const GaussianDistribution &operator>>(Double &) const;
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

            virtual void validateParam(std::tuple<A, B>) const override;

            const GammaDistribution &operator>>(Double &) const;
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

            virtual void validateParam(Mu) const override;

            const PoissonDistribution &operator>>(UInt &) const;
    };
}

#endif // GSLER_RANDOM_DISTRIBUTION_INC
