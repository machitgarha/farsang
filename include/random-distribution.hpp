#ifndef GSLER_RANDOM_DISTRIBUTION_INC
#define GSLER_RANDOM_DISTRIBUTION_INC

#include "random-generator.hpp"

namespace Gsler
{
    class RandomDistribution
    {
        public:
            using Double = double;
            using UInt = unsigned int;

            RandomDistribution() = delete;
            RandomDistribution(const RandomGenerator &);

            // Only for making class abstract
            virtual ~RandomDistribution() = 0;

            virtual const RandomGenerator &getGenerator() const noexcept final;

        private:
            const RandomGenerator &generator;
    };

    class GaussianDistribution: public RandomDistribution
    {
        public:
            using Sigma = Double;

            GaussianDistribution() = delete;
            GaussianDistribution(const RandomGenerator &, Sigma);

            using RandomDistribution::RandomDistribution;

            // Uses default sigma
            virtual Double get() const noexcept final;
            virtual Double get(Sigma) const noexcept final;

            virtual inline Sigma getParamSigma() const noexcept final
            {
                return this->sigma;
            }
            virtual inline void setParamSigma(Sigma sigma) noexcept final
            {
                this->sigma = sigma;
            }

        private:
            // Defaults to unit Gaussian distribution
            Sigma sigma = 1.0;
    };

    class GammaDistribution: public RandomDistribution
    {
        public:
            GammaDistribution() = delete;
            using RandomDistribution::RandomDistribution;

            virtual Double get(Double, Double) const noexcept final;
    };

    class PoissonDistribution: public RandomDistribution
    {
        public:
            PoissonDistribution() = delete;
            using RandomDistribution::RandomDistribution;

            virtual UInt get(Double) const noexcept final;
    };
}

#endif // GSLER_RANDOM_DISTRIBUTION_INC
