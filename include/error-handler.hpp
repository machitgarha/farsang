#ifndef GSLER_ERROR_HANDLER_INC
#define GSLER_ERROR_HANDLER_INC

#include <gsl/gsl_errno.h>

namespace Gsler
{
    class ErrorHandler
    {
        public:
            using Message = const char *;
            using FilePath = const char *;
            using Line = int;
            using ErrorCode = int;

            ErrorHandler() = delete;
            ErrorHandler(const ErrorHandler &) = delete;
            ErrorHandler(const ErrorHandler &&) = delete;
            ~ErrorHandler() = delete;

        protected:
            // The functional part of the class is here
            static void handle(const Message, const FilePath, const Line, const ErrorCode);

        private:
            // Preparing error handler before starting main
            static const bool _prepare;
            static bool prepare() noexcept(true);
    };
}

#endif // GSLER_ERROR_HANDLER_INC
