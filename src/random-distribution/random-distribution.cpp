#include "random-distribution.hpp"

using namespace Gsler;

/* TODO:
 * Implement RandomDistribution here, and specialize it later when needed.
 * Unfortunately, it is not possible for now, because of my limited knowledge.
 * The current implementation is a dirty hack.
 */

template<typename ParamType>
RandomDistribution<ParamType>::~RandomDistribution()
{
}

// Regarding the comments above, these should not be here
template RandomDistribution<double>::~RandomDistribution();
template RandomDistribution<std::tuple<double, double>>::~RandomDistribution();
