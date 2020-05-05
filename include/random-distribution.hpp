#ifndef GSLER_RANDOM_DISTRIBUTION_INC
#define GSLER_RANDOM_DISTRIBUTION_INC

#include "random-generator.hpp"
#include "exception.hpp"

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
            using A = Double;
            using B = Double;

            GammaDistribution() = delete;
            GammaDistribution(const RandomGenerator &, A, B);

            using RandomDistribution::RandomDistribution;

            // Uses default a and b
            virtual Double get() const final;
            virtual Double get(A, B) const noexcept final;

            virtual inline A getParamA() const final
            {
                if (!this->isParamASet) {
                    throw Exception::Exception("Parameter A is not set");
                }
                return this->a;
            }
            virtual inline GammaDistribution &setParamA(A a) noexcept final
            {
                this->a = a;
                this->isParamASet = true;
                return *this;
            }
            virtual inline bool isSetParamA() const noexcept final
            {
                return this->isParamASet;
            }

            virtual inline B getParamB() const final
            {
                if (!this->isParamBSet) {
                    throw Exception::Exception("Parameter B is not set");
                }
                return this->b;
            }
            virtual inline GammaDistribution &setParamB(B b) noexcept final
            {
                this->b = b;
                this->isParamBSet = true;
                return *this;
            }
            virtual inline bool isSetParamB() const noexcept final
            {
                return this->isParamBSet;
            }

        private:
            A a;
            B b;
            bool isParamASet = false;
            bool isParamBSet = false;
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
