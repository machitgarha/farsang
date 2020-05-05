#ifndef GSLER_RANDOM_DISTRIBUTION_INC
#define GSLER_RANDOM_DISTRIBUTION_INC

#include "random-generator.hpp"

namespace Gsler
{
    class RandomDistribution
    {
        public:
            RandomDistribution() = delete;
            RandomDistribution(const RandomGenerator &);

            // Only for making class abstract
            virtual ~RandomDistribution() = 0;

            virtual const RandomGenerator &getGenerator() const noexcept final;

        private:
            const RandomGenerator &generator;
    };
}

#endif // GSLER_RANDOM_DISTRIBUTION_INC
