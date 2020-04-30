#ifndef GSLER_RANDOM_GERERATOR_INC
#define GSLER_RANDOM_GERERATOR_INC

#include <gsl/gsl_rng.h>

namespace Gsler
{
    class RandomGenerator
    {
        public:
            using Seed = unsigned long int;
            using GeneratorType = gsl_rng_type *;

            RandomGenerator();
            RandomGenerator(const RandomGenerator &);
            ~RandomGenerator();

            const unsigned long int min;
            const unsigned long int max;

            unsigned long int generate() const noexcept(true);

            RandomGenerator &setSeed(const Seed);

            static const GeneratorType borosh13;
            static const GeneratorType coveyou;
            static const GeneratorType cmrg;
            static const GeneratorType fishman18;
            static const GeneratorType fishman20;
            static const GeneratorType fishman2x;
            static const GeneratorType gfsr4;
            static const GeneratorType knuthran;
            static const GeneratorType knuthran2;
            static const GeneratorType knuthran2002;
            static const GeneratorType lecuyer21;
            static const GeneratorType minstd;
            static const GeneratorType mrg;
            static const GeneratorType mt19937;
            static const GeneratorType mt19937_1999;
            static const GeneratorType mt19937_1998;
            static const GeneratorType r250;
            static const GeneratorType ran0;
            static const GeneratorType ran1;
            static const GeneratorType ran2;
            static const GeneratorType ran3;
            static const GeneratorType rand;
            static const GeneratorType rand48;
            static const GeneratorType random128_bsd;
            static const GeneratorType random128_glibc2;
            static const GeneratorType random128_libc5;
            static const GeneratorType random256_bsd;
            static const GeneratorType random256_glibc2;
            static const GeneratorType random256_libc5;
            static const GeneratorType random32_bsd;
            static const GeneratorType random32_glibc2;
            static const GeneratorType random32_libc5;
            static const GeneratorType random64_bsd;
            static const GeneratorType random64_glibc2;
            static const GeneratorType random64_libc5;
            static const GeneratorType random8_bsd;
            static const GeneratorType random8_glibc2;
            static const GeneratorType random8_libc5;
            static const GeneratorType random_bsd;
            static const GeneratorType random_glibc2;
            static const GeneratorType random_libc5;
            static const GeneratorType randu;
            static const GeneratorType ranf;
            static const GeneratorType ranlux;
            static const GeneratorType ranlux389;
            static const GeneratorType ranlxd1;
            static const GeneratorType ranlxd2;
            static const GeneratorType ranlxs0;
            static const GeneratorType ranlxs1;
            static const GeneratorType ranlxs2;
            static const GeneratorType ranmar;
            static const GeneratorType slatec;
            static const GeneratorType taus;
            static const GeneratorType taus2;
            static const GeneratorType taus113;
            static const GeneratorType transputer;
            static const GeneratorType tt800;
            static const GeneratorType uni;
            static const GeneratorType uni32;
            static const GeneratorType vax;
            static const GeneratorType waterman14;
            static const GeneratorType zuf;            

            static void setupEnvironment();

        protected:
            void allocate();
            void free() noexcept(true);

            static void checkErrors();

        private:
            using Generator = gsl_rng *;

            Generator generator;
            GeneratorType generatorType;
    };
}

#endif // GSLER_RANDOM_GERERATOR_INC
