#include "random-generator.hpp"

#include "exception.hpp"

using namespace Farsang;
using namespace Farsang::Exception;

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

RandomGenerator::Seed RandomGenerator::defaultSeed = gsl_rng_default_seed;
const RandomGenerator::GeneratorType *RandomGenerator::defaultGeneratorType =
    gsl_rng_default;

RandomGenerator::RandomGenerator()
{
}

RandomGenerator::RandomGenerator(const Seed seed)
{
    this->seed(seed);
}

RandomGenerator::RandomGenerator(const GeneratorType *gType):
    generator(RandomGenerator::allocate(gType))
{
}

RandomGenerator::RandomGenerator(const GeneratorType *gType, const Seed seed):
    generator(RandomGenerator::allocate(gType))
{
    this->seed(seed);
}

RandomGenerator::RandomGenerator(const RandomGenerator &r):
    generator(RandomGenerator::clone(r.generator))
{
}

RandomGenerator::~RandomGenerator()
{
    this->free();
}

RandomGenerator::ULong RandomGenerator::getMin() const noexcept
{
    return gsl_rng_min(this->generator);
}

RandomGenerator::ULong RandomGenerator::getMax() const noexcept
{
    return gsl_rng_max(this->generator);
}

RandomGenerator::Name RandomGenerator::getName() const noexcept
{
    return gsl_rng_name(this->generator);
}

RandomGenerator::State RandomGenerator::getState() const noexcept
{
    return gsl_rng_state(this->generator);
}

RandomGenerator::Size RandomGenerator::getSize() const noexcept
{
    return gsl_rng_size(this->generator);
}

RandomGenerator::Seed RandomGenerator::getSeed() const noexcept
{
    return this->_seed;
}

const RandomGenerator::Generator *RandomGenerator::getGenerator() const noexcept
{
    return this->generator;
}

RandomGenerator::ULong RandomGenerator::generate() const noexcept
{
    return gsl_rng_get(this->generator);
}

RandomGenerator::ULong RandomGenerator::generate(const Min min, const Max max) const
{
    if (min >= max) {
        throw InvalidArgumentException("Min is not lower than max");
    }

    return (this->generate() % (max - min + 1)) + min;
}


RandomGenerator::ULong RandomGenerator::generateUniform(Max max) const noexcept
{
    return gsl_rng_uniform_int(this->generator, max);
}

RandomGenerator::Double RandomGenerator::generateUniform() const noexcept
{
    return gsl_rng_uniform(this->generator);
}

RandomGenerator::Double RandomGenerator::generateUniformPos() const noexcept
{
    return gsl_rng_uniform_pos(this->generator);
}

RandomGenerator &RandomGenerator::seed(const Seed seed)
{
    gsl_rng_set(this->generator, seed);

    // Should be here in the case of errors
    this->_seed = seed;

    return *this;
}

RandomGenerator &RandomGenerator::fileRead(FILE *f)
{
    // TODO: Rethrow Exception as FileReadException
    gsl_rng_fread(f, this->generator);

    return *this;
}

RandomGenerator &RandomGenerator::fileRead(std::ifstream &f)
{
    size_t size = this->generator->type->size;
    char *state = static_cast<char *>(this->generator->state);

    try {
        f.read(state, size);
        if (!f.good()) {
            throw std::ios_base::failure("Could not read from file");
        }
    } catch (std::ios_base::failure &e) {
        throw FileReadException(e.what(), e.code().value());
    }

    return *this;
}

const RandomGenerator &RandomGenerator::fileWrite(FILE *f) const
{
    // TODO: Rethrow Exception as FileWriteException
    gsl_rng_fwrite(f, this->generator);

    return *this;
}

const RandomGenerator &RandomGenerator::fileWrite(std::ofstream &f) const
{
    size_t size = this->generator->type->size;
    char *state = static_cast<char *>(this->generator->state);

    try {
        f.write(state, size);
        if (!f.good()) {
            throw std::ios_base::failure("Could not write to file");
        }
    } catch (std::ios_base::failure &e) {
        throw FileWriteException(e.what(), e.code().value());
    }

    return *this;
}

void RandomGenerator::setupEnvironment()
{
    // TODO: Add an option to supress the output of the following function (stderr)
    gsl_rng_env_setup();

    // Update static variables
    RandomGenerator::setDefaultSeed(gsl_rng_default_seed);
    RandomGenerator::setDefaultGeneratorType(gsl_rng_default);
}

RandomGenerator::Seed RandomGenerator::getDefaultSeed() noexcept
{
    return RandomGenerator::defaultSeed;
}

void RandomGenerator::setDefaultSeed(const Seed seed) noexcept
{
    RandomGenerator::defaultSeed = seed;
}

const RandomGenerator::GeneratorType *RandomGenerator::getDefaultGeneratorType() noexcept
{
    return RandomGenerator::defaultGeneratorType;
}

void RandomGenerator::setDefaultGeneratorType(const GeneratorType *e) noexcept
{
    RandomGenerator::defaultGeneratorType = e;
}

void RandomGenerator::free() noexcept
{
    gsl_rng_free(this->generator);
}

RandomGenerator::Generator *RandomGenerator::allocate()
{
    return gsl_rng_alloc(RandomGenerator::getDefaultGeneratorType());
}

RandomGenerator::Generator *RandomGenerator::allocate(const GeneratorType *t)
{
    return gsl_rng_alloc(t);
}

RandomGenerator::Generator *RandomGenerator::clone(const Generator *g)
{
    return gsl_rng_clone(g);
}

// Class-independent stuff

FILE *Farsang::operator>>(FILE *f, RandomGenerator &rGenerator)
{
    rGenerator.fileRead(f);
    return f;
}

std::ifstream &Farsang::operator>>(std::ifstream &f, RandomGenerator &rGenerator)
{
    rGenerator.fileRead(f);
    return f;
}

FILE *Farsang::operator<<(FILE *f, RandomGenerator &rGenerator)
{
    rGenerator.fileWrite(f);
    return f;
}

std::ofstream &Farsang::operator<<(std::ofstream &f, RandomGenerator &rGenerator)
{
    rGenerator.fileWrite(f);
    return f;
}
