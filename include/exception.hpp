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
                using Message = const char *;
                using MessageString = std::string;

                Exception() = delete;
                Exception(const Message &) noexcept;
                Exception(const MessageString &) noexcept;

                virtual Message what() const noexcept;

            private:
                MessageString message;
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
