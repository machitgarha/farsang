# Gsler

## Known Issues

### Template Instantiation Linker Error

In RandomDistribution class and its children (e.g. PoissonDistribution class), there is a linking error. You can review this issue in `issue-template-linker-error` branch.

#### Fixes

Currently, there are two (temporary?) fixes:

-   Define all base class methods inline, instead of separating declaration and definition.
    -   Branch: `issue-template-linker-error-fix-1`

-   Move explicit instantiation statements into the definition of base class. In other words, compile instantiations and templated class definitions together in one translation unit.
    -   Branch: `issue-template-linker-error-fix-2`
