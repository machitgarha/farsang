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

                virtual const char *getMessage() const noexcept final;
                virtual const char *getPath() const noexcept final;
                virtual Line getLine() const noexcept final;
                virtual Code getCode() const noexcept final;

                virtual bool hasPath() const noexcept final;
                virtual bool hasLine() const noexcept final;
                virtual bool hasCode() const noexcept final;

            protected:
                virtual void prepareWhat();
                virtual void prepareWhere();

                virtual inline void prepare()
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
        };
    }
}

#endif // GSLER_EXCEPTION_INC
