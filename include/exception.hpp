#ifndef GSLER_EXCEPTION_INC
#define GSLER_EXCEPTION_INC

#include <stdexcept>

namespace Gsler
{
    namespace Exception
    {
        class Exception: public std::exception
        {
            public:
                using Message = std::string;

                Exception() = delete;
                Exception(const Message &) noexcept;

                virtual const char *what() const noexcept;

            private:
                Message message;
        };

        class LogicException: public Exception
        {
            public:
                LogicException() = delete;
                using Exception::Exception;

                using Exception::what;
        };
    }
}

#endif // GSLER_EXCEPTION_INC
