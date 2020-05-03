#ifndef GSLER_EXCEPTION_INC
#define GSLER_EXCEPTION_INC

#include <stdexcept>

#define EXCEPTION(...)\
    Gsler::Exception::Exception(__VA_ARGS__, __FILE__, __LINE__)
#define LOGIC_EXCEPTION(...)\
    Gsler::Exception::LogicException(__VA_ARGS__, __FILE__, __LINE__)

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
                Exception(const Exception &) = default;
                Exception(Exception &&) = default;

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

                virtual bool hasWhere() const noexcept final;

                virtual inline Code getDefaultCode() const noexcept { return 1; }

            protected:
                virtual void prepareWhat();
                virtual void prepareWhere();

                virtual inline void prepare()
                {
                    // Note the order, we may use prepareWhere() in prepareWhat()
                    this->prepareWhere();
                    this->prepareWhat();
                }

            private:
                const Message message;
                const Path path = Exception::PATH_UNKNOWN;
                const Line line = Exception::LINE_UNKNOWN;
                const Code code = Exception::CODE_UNKNOWN;

                std::string whatStr = "";
                std::string whereStr = "";
        };
    }
}

#endif // GSLER_EXCEPTION_INC
