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
                using Path = const char *;
                using Line = unsigned long int;
                using Code = unsigned short int;

                static const Path PATH_UNKNOWN;
                static const Line LINE_UNKNOWN;
                static const Code CODE_UNKNOWN;

                static const char *WHERE_UNKNOWN;

                Exception() = delete;
                Exception(const Message &);
                Exception(const Message &, const Code);
                Exception(const Message &, const Path, const Line);
                Exception(const Message &, const Code, const Path, const Line);

                virtual const char *what() const noexcept;
                virtual const char *where() const noexcept;

                virtual const char *getMessage() const noexcept;
                virtual const char *getPath() const noexcept;
                virtual Code getCode() const noexcept;
                virtual Line getLine() const noexcept;

            protected:
                virtual void prepareWhat() const;
                virtual void prepareWhere() const;

                virtual inline void prepare() const
                {
                    Exception::prepareWhat();
                    Exception::prepareWhere();
                }

            private:
                const Message message;
                const Path path = Exception::PATH_UNKNOWN;
                const Line line = Exception::LINE_UNKNOWN;
                const Code code = Exception::CODE_UNKNOWN;

                std::string whatStr = "";
                std::string whereStr = "";
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
