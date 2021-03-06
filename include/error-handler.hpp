#ifndef FARSANG_ERROR_HANDLER_INC
#define FARSANG_ERROR_HANDLER_INC

#include <gsl/gsl_errno.h>

namespace Farsang
{
    class ErrorHandler
    {
        public:
            using Message = const char *;
            using Path = const char *;
            using Line = int;
            using Code = int;

            ErrorHandler() = delete;
            ErrorHandler(const ErrorHandler &) = delete;
            ErrorHandler(const ErrorHandler &&) = delete;
            ~ErrorHandler() = delete;

            // To report the location of the error or not
            static inline void showLocation() noexcept
            { ErrorHandler::toShowLocation = true; };
            static inline void hideLocation() noexcept
            { ErrorHandler::toShowLocation = false; };

        protected:
            // The functional part of the class is here
            static void handle(const Message, const Path, const Line, const Code);

        private:
            static bool toShowLocation;

            // Preparing error handler before starting main
            static const bool _prepare;
            static bool prepare() noexcept(true);
    };
}

#endif // FARSANG_ERROR_HANDLER_INC
