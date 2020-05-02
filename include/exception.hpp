#ifndef GSLER_EXCEPTION_INC
#define GSLER_EXCEPTION_INC

#include <stdexcept>

namespace Gsler
{
    class Exception: public std::exception
    {
        public:
            using Message = const char *;
            using MessageString = const std::string;

            Exception() = delete;
            Exception(const Message &) noexcept(true);
            Exception(const MessageString &) noexcept(true);

            virtual Message what() const noexcept(true);

        private:
            const MessageString message;
    };
}

#endif // GSLER_EXCEPTION_INC
