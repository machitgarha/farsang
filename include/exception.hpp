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
                using Path = std::string;
                using Line = unsigned long int;
                using Code = unsigned short int;

                using Location = struct
                {
                    Path path;
                    Line line;
                };

                static const Path PATH_UNKNOWN;
                static const Line LINE_UNKNOWN;
                static const Code CODE_UNKNOWN;

                Exception() = delete;
                Exception(const Message &);
                Exception(const Message &, const Code);
                Exception(const Message &, const Location &);
                Exception(const Message &, const Code, const Location &);
                Exception(const Message &, const Path &, const Line);
                Exception(const Message &, const Code, const Path &, const Line);

                virtual const char *what() const noexcept;
                virtual const char *where() const noexcept;

                virtual const char *getMessage() const noexcept;
                virtual const char *getPath() const noexcept;
                virtual Code getCode() const noexcept;
                virtual Line getLine() const noexcept;

                // TODO: Add prepareWhat() protected

            private:
                Message message;
                Path path = PATH_UNKNOWN;
                Line line = LINE_UNKNOWN;
                Code code = CODE_UNKNOWN;
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
