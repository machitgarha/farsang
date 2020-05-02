#ifndef GSLER_ERROR_HANDLER_INC
#define GSLER_ERROR_HANDLER_INC

#include <gsl/gsl_errno.h>

namespace Gsler
{
    class ErrorHandler
    {
        public:
            ErrorHandler() = delete;
            ErrorHandler(const ErrorHandler &) = delete;
            ErrorHandler(const ErrorHandler &&) = delete;
            ~ErrorHandler() = delete;

            static void checkErrors();

        private:
            // For preparing before main
            static const bool _prepare;
            static bool prepare() noexcept(true);
    };
}

#endif // GSLER_ERROR_HANDLER_INC
