#ifndef FARSANG_RANDOM_GERERATOR_INC
#define FARSANG_RANDOM_GERERATOR_INC

#include <string>
#include <fstream>
#include <gsl/gsl_rng.h>
#include "error-handler.hpp"

namespace Farsang
{
    class RandomGenerator
    {
        public:
            using ULong = unsigned long int;
            using Min = ULong;
            using Max = ULong;
            using Seed = ULong;
            using Double = double;
            using Generator = gsl_rng;
            using GeneratorType = gsl_rng_type;
            using Name = const char *;
            using State = void *;
            using Size = size_t;

            static const GeneratorType *const borosh13;
            static const GeneratorType *const coveyou;
            static const GeneratorType *const cmrg;
            static const GeneratorType *const fishman18;
            static const GeneratorType *const fishman20;
            static const GeneratorType *const fishman2x;
            static const GeneratorType *const gfsr4;
            static const GeneratorType *const knuthran;
            static const GeneratorType *const knuthran2;
            static const GeneratorType *const knuthran2002;
            static const GeneratorType *const lecuyer21;
            static const GeneratorType *const minstd;
            static const GeneratorType *const mrg;
            static const GeneratorType *const mt19937;
            static const GeneratorType *const mt19937_1999;
            static const GeneratorType *const mt19937_1998;
            static const GeneratorType *const r250;
            static const GeneratorType *const ran0;
            static const GeneratorType *const ran1;
            static const GeneratorType *const ran2;
            static const GeneratorType *const ran3;
            static const GeneratorType *const rand;
            static const GeneratorType *const rand48;
            static const GeneratorType *const random128_bsd;
            static const GeneratorType *const random128_glibc2;
            static const GeneratorType *const random128_libc5;
            static const GeneratorType *const random256_bsd;
            static const GeneratorType *const random256_glibc2;
            static const GeneratorType *const random256_libc5;
            static const GeneratorType *const random32_bsd;
            static const GeneratorType *const random32_glibc2;
            static const GeneratorType *const random32_libc5;
            static const GeneratorType *const random64_bsd;
            static const GeneratorType *const random64_glibc2;
            static const GeneratorType *const random64_libc5;
            static const GeneratorType *const random8_bsd;
            static const GeneratorType *const random8_glibc2;
            static const GeneratorType *const random8_libc5;
            static const GeneratorType *const random_bsd;
            static const GeneratorType *const random_glibc2;
            static const GeneratorType *const random_libc5;
            static const GeneratorType *const randu;
            static const GeneratorType *const ranf;
            static const GeneratorType *const ranlux;
            static const GeneratorType *const ranlux389;
            static const GeneratorType *const ranlxd1;
            static const GeneratorType *const ranlxd2;
            static const GeneratorType *const ranlxs0;
            static const GeneratorType *const ranlxs1;
            static const GeneratorType *const ranlxs2;
            static const GeneratorType *const ranmar;
            static const GeneratorType *const slatec;
            static const GeneratorType *const taus;
            static const GeneratorType *const taus2;
            static const GeneratorType *const taus113;
            static const GeneratorType *const transputer;
            static const GeneratorType *const tt800;
            static const GeneratorType *const uni;
            static const GeneratorType *const uni32;
            static const GeneratorType *const vax;
            static const GeneratorType *const waterman14;
            static const GeneratorType *const zuf;

            RandomGenerator();
            RandomGenerator(const Seed);
            RandomGenerator(const GeneratorType *);
            RandomGenerator(const GeneratorType *, const Seed);
            RandomGenerator(const RandomGenerator &);
            ~RandomGenerator();

            ULong getMin() const noexcept;
            ULong getMax() const noexcept;

            Name getName() const noexcept;

            State getState() const noexcept;
            Size getSize() const noexcept;

            Seed getSeed() const noexcept;

            const Generator *getGenerator() const noexcept;

            ULong generate() const noexcept;
            ULong generate(const Min, const Max) const;

            ULong generateUniform(Max) const noexcept;
            Double generateUniform() const noexcept;
            Double generateUniformPos() const noexcept;

            RandomGenerator &seed(const Seed);

            RandomGenerator &fileRead(FILE *);
            RandomGenerator &fileRead(std::ifstream &);

            const RandomGenerator &fileWrite(FILE *) const;
            const RandomGenerator &fileWrite(std::ofstream &) const;

            static void setupEnvironment();

            static Seed getDefaultSeed() noexcept;
            static void setDefaultSeed(const Seed) noexcept;

            static const GeneratorType *getDefaultGeneratorType() noexcept;
            static void setDefaultGeneratorType(const GeneratorType *) noexcept;

        protected:
            void free() noexcept;

            // Uses default generator type
            static Generator *allocate();
            static Generator *allocate(const GeneratorType *);

            static Generator *clone(const Generator *);

        private:
            Generator *generator = RandomGenerator::allocate();
            Seed _seed = RandomGenerator::defaultSeed;

            static Seed defaultSeed;
            static const GeneratorType *defaultGeneratorType;
    };

    FILE *operator>>(FILE *, RandomGenerator &);
    std::ifstream &operator>>(std::ifstream &, RandomGenerator &);

    FILE *operator<<(FILE *, RandomGenerator &);
    std::ofstream &operator<<(std::ofstream &, RandomGenerator &);
}

#endif // FARSANG_RANDOM_GERERATOR_INC
