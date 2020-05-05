#include <iostream>
#include "random-distribution.hpp"

using namespace std;
using namespace Gsler;

int main()
{
    try {
        RandomGenerator::setupEnvironment();

        RandomGenerator r(time(0));

        PoissonDistribution pDist(r);
        unsigned int k;
        double sigma;

        cout << "Enter Poisson's Mu parameter:" << endl;
        cin >> sigma;
        pDist.setParam(sigma);

        for (size_t i = 1; i <= 10; i += 2) {
            pDist >> k;
            cout << "Poisson distribution number " << i << ": " << k << endl;

            k = pDist.get();
            cout << "Poisson distribution number " << i + 1 << ": " << k << endl;
        }

        r.seed(time(0));

        GammaDistribution gDist(r);

        double a, b;
        cout << endl;
        cout << "Enter Gamma's a and b parameters:" << endl;
        cin >> a >> b;

        for (size_t i = 1; i <= 10; i += 2) {
            cout << "Gamma distribution number " << i << ": " << gDist.get({a, b}) << endl;
            cout << "Gamma distribution number " << i + 1 << ": " << gDist.get(a, b) << endl;
        }

        RandomGenerator r2(RandomGenerator::taus, time(0));

        GaussianDistribution gaDist(r2);
        gaDist.setParam(1);

        cout << endl;
        cout << "A sample Gaussian distribution: " << gaDist.get() << endl;
        cout << "Information:" << endl;
        cout << "Random generator:" << endl;
        cout << "Name: " << r2.getName() << endl;
        cout << "Min: " << r2.getMin() << endl;
        cout << "Max: " << r2.getMax() << endl;
        cout << "Seed: " << r2.getSeed() << endl;
        cout << "Distribution:" << endl;
        cout << "Sigma = " << gaDist.getParam() << endl;
    }
    catch (Exception::InvalidArgumentException &e) {
        cout << "Invalid argument passed:" << endl;
        cout << e.what() << endl;
        return e.getCode();
    }
    catch (Exception::ArithmeticException &e) {
        cout << "Arithmetic error:" << endl;
        cout << e.what() << endl;
        return e.getCode();
    }
    catch (Exception::Exception &e) {
        cout << "Error happened:" << endl;
        cout << e.what() << endl;
        return e.getCode();
    }

    return 0;
}
