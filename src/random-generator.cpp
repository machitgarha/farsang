#include "random-generator.hpp"

#include <gsl/gsl_errno.h>

using namespace Gsler;

const RandomGenerator::GeneratorType *const RandomGenerator::borosh13 =
    gsl_rng_borosh13;
const RandomGenerator::GeneratorType *const RandomGenerator::coveyou =
    gsl_rng_coveyou;
const RandomGenerator::GeneratorType *const RandomGenerator::cmrg =
    gsl_rng_cmrg;
const RandomGenerator::GeneratorType *const RandomGenerator::fishman18 =
    gsl_rng_fishman18;
const RandomGenerator::GeneratorType *const RandomGenerator::fishman20 =
    gsl_rng_fishman20;
const RandomGenerator::GeneratorType *const RandomGenerator::fishman2x =
    gsl_rng_fishman2x;
const RandomGenerator::GeneratorType *const RandomGenerator::gfsr4 =
    gsl_rng_gfsr4;
const RandomGenerator::GeneratorType *const RandomGenerator::knuthran =
    gsl_rng_knuthran;
const RandomGenerator::GeneratorType *const RandomGenerator::knuthran2 =
    gsl_rng_knuthran2;
const RandomGenerator::GeneratorType *const RandomGenerator::knuthran2002 =
    gsl_rng_knuthran2002;
const RandomGenerator::GeneratorType *const RandomGenerator::lecuyer21 =
    gsl_rng_lecuyer21;
const RandomGenerator::GeneratorType *const RandomGenerator::minstd =
    gsl_rng_minstd;
const RandomGenerator::GeneratorType *const RandomGenerator::mrg =
    gsl_rng_mrg;
const RandomGenerator::GeneratorType *const RandomGenerator::mt19937 =
    gsl_rng_mt19937;
const RandomGenerator::GeneratorType *const RandomGenerator::mt19937_1999 =
    gsl_rng_mt19937_1999;
const RandomGenerator::GeneratorType *const RandomGenerator::mt19937_1998 =
    gsl_rng_mt19937_1998;
const RandomGenerator::GeneratorType *const RandomGenerator::r250 =
    gsl_rng_r250;
const RandomGenerator::GeneratorType *const RandomGenerator::ran0 =
    gsl_rng_ran0;
const RandomGenerator::GeneratorType *const RandomGenerator::ran1 =
    gsl_rng_ran1;
const RandomGenerator::GeneratorType *const RandomGenerator::ran2 =
    gsl_rng_ran2;
const RandomGenerator::GeneratorType *const RandomGenerator::ran3 =
    gsl_rng_ran3;
const RandomGenerator::GeneratorType *const RandomGenerator::rand =
    gsl_rng_rand;
const RandomGenerator::GeneratorType *const RandomGenerator::rand48 =
    gsl_rng_rand48;
const RandomGenerator::GeneratorType *const RandomGenerator::random128_bsd =
    gsl_rng_random128_bsd;
const RandomGenerator::GeneratorType *const RandomGenerator::random128_glibc2 =
    gsl_rng_random128_glibc2;
const RandomGenerator::GeneratorType *const RandomGenerator::random128_libc5 =
    gsl_rng_random128_libc5;
const RandomGenerator::GeneratorType *const RandomGenerator::random256_bsd =
    gsl_rng_random256_bsd;
const RandomGenerator::GeneratorType *const RandomGenerator::random256_glibc2 =
    gsl_rng_random256_glibc2;
const RandomGenerator::GeneratorType *const RandomGenerator::random256_libc5 =
    gsl_rng_random256_libc5;
const RandomGenerator::GeneratorType *const RandomGenerator::random32_bsd =
    gsl_rng_random32_bsd;
const RandomGenerator::GeneratorType *const RandomGenerator::random32_glibc2 =
    gsl_rng_random32_glibc2;
const RandomGenerator::GeneratorType *const RandomGenerator::random32_libc5 =
    gsl_rng_random32_libc5;
const RandomGenerator::GeneratorType *const RandomGenerator::random64_bsd =
    gsl_rng_random64_bsd;
const RandomGenerator::GeneratorType *const RandomGenerator::random64_glibc2 =
    gsl_rng_random64_glibc2;
const RandomGenerator::GeneratorType *const RandomGenerator::random64_libc5 =
    gsl_rng_random64_libc5;
const RandomGenerator::GeneratorType *const RandomGenerator::random8_bsd =
    gsl_rng_random8_bsd;
const RandomGenerator::GeneratorType *const RandomGenerator::random8_glibc2 =
    gsl_rng_random8_glibc2;
const RandomGenerator::GeneratorType *const RandomGenerator::random8_libc5 =
    gsl_rng_random8_libc5;
const RandomGenerator::GeneratorType *const RandomGenerator::random_bsd =
    gsl_rng_random_bsd;
const RandomGenerator::GeneratorType *const RandomGenerator::random_glibc2 =
    gsl_rng_random_glibc2;
const RandomGenerator::GeneratorType *const RandomGenerator::random_libc5 =
    gsl_rng_random_libc5;
const RandomGenerator::GeneratorType *const RandomGenerator::randu =
    gsl_rng_randu;
const RandomGenerator::GeneratorType *const RandomGenerator::ranf =
    gsl_rng_ranf;
const RandomGenerator::GeneratorType *const RandomGenerator::ranlux =
    gsl_rng_ranlux;
const RandomGenerator::GeneratorType *const RandomGenerator::ranlux389 =
    gsl_rng_ranlux389;
const RandomGenerator::GeneratorType *const RandomGenerator::ranlxd1 =
    gsl_rng_ranlxd1;
const RandomGenerator::GeneratorType *const RandomGenerator::ranlxd2 =
    gsl_rng_ranlxd2;
const RandomGenerator::GeneratorType *const RandomGenerator::ranlxs0 =
    gsl_rng_ranlxs0;
const RandomGenerator::GeneratorType *const RandomGenerator::ranlxs1 =
    gsl_rng_ranlxs1;
const RandomGenerator::GeneratorType *const RandomGenerator::ranlxs2 =
    gsl_rng_ranlxs2;
const RandomGenerator::GeneratorType *const RandomGenerator::ranmar =
    gsl_rng_ranmar;
const RandomGenerator::GeneratorType *const RandomGenerator::slatec =
    gsl_rng_slatec;
const RandomGenerator::GeneratorType *const RandomGenerator::taus =
    gsl_rng_taus;
const RandomGenerator::GeneratorType *const RandomGenerator::taus2 =
    gsl_rng_taus2;
const RandomGenerator::GeneratorType *const RandomGenerator::taus113 =
    gsl_rng_taus113;
const RandomGenerator::GeneratorType *const RandomGenerator::transputer =
    gsl_rng_transputer;
const RandomGenerator::GeneratorType *const RandomGenerator::tt800 =
    gsl_rng_tt800;
const RandomGenerator::GeneratorType *const RandomGenerator::uni =
    gsl_rng_uni;
const RandomGenerator::GeneratorType *const RandomGenerator::uni32 =
    gsl_rng_uni32;
const RandomGenerator::GeneratorType *const RandomGenerator::vax =
    gsl_rng_vax;
const RandomGenerator::GeneratorType *const RandomGenerator::waterman14 =
    gsl_rng_waterman14;
const RandomGenerator::GeneratorType *const RandomGenerator::zuf =
    gsl_rng_zuf;

RandomGenerator::RandomGenerator():
    generatorType(gsl_rng_default),
    generator(this->allocate(this->generatorType)),
    min(gsl_rng_min(this->generator)),
    max(gsl_rng_max(this->generator))
{
    // Implicit error checking in allocate()
}

RandomGenerator::RandomGenerator(const GeneratorType *t):
    generatorType(t),
    generator(this->allocate(this->generatorType)),
    min(gsl_rng_min(this->generator)),
    max(gsl_rng_max(this->generator))
{
    // Implicit error checking in allocate()
}

RandomGenerator::RandomGenerator(const RandomGenerator &r):
    generatorType(r.generatorType),
    generator(this->allocate(this->generatorType)),
    min(r.min),
    max(r.max)
{
    // Implicit error checking in allocate()
}

RandomGenerator::~RandomGenerator()
{
    this->free();
}

RandomGenerator::ULong RandomGenerator::getMin() const noexcept(true)
{
    return this->min;
}

RandomGenerator::ULong RandomGenerator::getMax() const noexcept(true)
{
    return this->max;
}

RandomGenerator::ULong RandomGenerator::generate() const noexcept(true)
{
    return gsl_rng_get(this->generator);
}

RandomGenerator &RandomGenerator::setSeed(const Seed seed)
{
    gsl_rng_set(this->generator, seed);

    RandomGenerator::checkErrors();

    return *this;
}

void RandomGenerator::setupEnvironment()
{
    gsl_rng_env_setup();

    RandomGenerator::checkErrors();
}

void RandomGenerator::free() noexcept(true)
{
    gsl_rng_free(this->generator);
}

void RandomGenerator::checkErrors()
{
    // TODO: Implement this
}

RandomGenerator::Generator *RandomGenerator::allocate(const GeneratorType *t)
{
    Generator *generator = gsl_rng_alloc(t);

    RandomGenerator::checkErrors();

    return generator;
}
