#ifndef GSLER_RANDOM_GERERATOR_INC
#define GSLER_RANDOM_GERERATOR_INC

#include <string>
#include <fstream>
#include <gsl/gsl_rng.h>

namespace Gsler
{
    class RandomGenerator
    {
        public:
            using ULong = unsigned long int;
            using Max = ULong;
            using Seed = ULong;
            using Double = double;
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

            ULong getMin() const noexcept(true);
            ULong getMax() const noexcept(true);

            const Name getName() const noexcept(true);

            State getState() const noexcept(true);
            Size getSize() const noexcept(true);

            Seed getSeed() const noexcept(true);

            ULong generate() const noexcept(true);

            ULong generateUniform(Max) const noexcept(true);
            Double generateUniform() const noexcept(true);
            Double generateUniformPos() const noexcept(true);

            RandomGenerator &seed(const Seed);

            RandomGenerator &fileRead(FILE *);
            RandomGenerator &fileRead(std::ifstream &);

            const RandomGenerator &fileWrite(FILE *) const;
            const RandomGenerator &fileWrite(std::ofstream &) const;

            static void setupEnvironment();

            static Seed getGlobalSeed() noexcept(true);
            static void setGlobalSeed(const Seed) noexcept(true);

        protected:
            using Generator = gsl_rng;

            void free() noexcept(true);

            static void checkErrors();

            static Generator *allocate(const GeneratorType *);
            static Generator *clone(const Generator *);

        private:
            const GeneratorType *generatorType;
            Generator *generator;
            Seed _seed = RandomGenerator::defaultSeed;

            static Seed defaultSeed;
    };

    FILE *operator>>(FILE *, RandomGenerator &);
    std::ifstream &operator>>(std::ifstream &, RandomGenerator &);

    FILE *operator<<(FILE *, RandomGenerator &);
    std::ofstream &operator<<(std::ofstream &, RandomGenerator &);
}

#endif // GSLER_RANDOM_GERERATOR_INC
