#ifndef GSLER_RANDOM_DISTRIBUTION_INC
#define GSLER_RANDOM_DISTRIBUTION_INC

#include "random-generator.hpp"

namespace Gsler
{
    class RandomDistribution
    {
        public:
            using Double = double;

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
            GaussianDistribution() = delete;
            using RandomDistribution::RandomDistribution;

            virtual Double get(Double = 1) const noexcept;
    };
}

#endif // GSLER_RANDOM_DISTRIBUTION_INC
