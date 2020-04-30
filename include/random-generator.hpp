#ifndef GSLER_RANDOM_GERERATOR_INC
#define GSLER_RANDOM_GERERATOR_INC

#include <gsl/gsl_rng.h>

namespace Gsler
{
    class RandomGenerator
    {
        public:
            RandomGenerator();
            ~RandomGenerator();

        private:
            gsl_rng *generator;
            gsl_rng_type *generatorType;
    };
}

#endif // GSLER_RANDOM_GERERATOR_INC
