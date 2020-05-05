#ifndef GSLER_EXCEPTION_INC
#define GSLER_EXCEPTION_INC

#include <stdexcept>
#include <asm-generic/errno-base.h>

#define EXCEPTION(...)\
    Gsler::Exception::Exception(__VA_ARGS__, __FILE__, __LINE__)
#define LOGIC_EXCEPTION(...)\
    Gsler::Exception::LogicException(__VA_ARGS__, __FILE__, __LINE__)

namespace Gsler
{
    namespace Exception
    {
        /**
         * Base exception of all Gsler exceptions.
         * TODO: Add comments here.
         */
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

                virtual bool isPathSet() const noexcept final;
                virtual bool isLineSet() const noexcept final;
                virtual bool isCodeSet() const noexcept final;
                virtual bool isLocationSet() const noexcept final;

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

        /**
         * Exceptions in which are mostly a base for other exceptions.
         * These exceptions, generally, have no POSIX-compatible error code.
         * Sorted by general number of uses (don't try to be precise).
         */

        class LogicException: public Exception
        {
            public:
                LogicException() = delete;
                LogicException(const LogicException &) = default;
                LogicException(LogicException &&) = default;

                using Exception::Exception;
        };

        class RuntimeException: public Exception
        {
            public:
                RuntimeException() = delete;
                RuntimeException(const RuntimeException &) = default;
                RuntimeException(RuntimeException &&) = default;

                using Exception::Exception;
        };

        class ArithmeticException: public RuntimeException
        {
            public:
                ArithmeticException() = delete;
                ArithmeticException(const ArithmeticException &) = default;
                ArithmeticException(ArithmeticException &&) = default;

                using RuntimeException::RuntimeException;
        };

        class IOException: public RuntimeException
        {
            public:
                IOException() = delete;
                IOException(const IOException &) = default;
                IOException(IOException &&) = default;

                using RuntimeException::RuntimeException;

                virtual inline Code getDefaultCode() const noexcept { return 5; }
        };

        /*
         * Exceptions that do have a POSIX-compatible error code.
         * Sorted by the error code.
         */

        class OutOfMemoryException: public RuntimeException
        {
            public:
                OutOfMemoryException() = delete;
                OutOfMemoryException(const OutOfMemoryException &) = default;
                OutOfMemoryException(OutOfMemoryException &&) = default;

                using RuntimeException::RuntimeException;

                virtual inline Code getDefaultCode() const noexcept { return 12; }
        };

        class InvalidPointerException: public LogicException
        {
            public:
                InvalidPointerException() = delete;
                InvalidPointerException(const InvalidPointerException &) = default;
                InvalidPointerException(InvalidPointerException &&) = default;

                using LogicException::LogicException;

                virtual inline Code getDefaultCode() const noexcept { return 14; }
        };

        class InvalidArgumentException: public LogicException
        {
            public:
                InvalidArgumentException() = delete;
                InvalidArgumentException(const InvalidArgumentException &) = default;
                InvalidArgumentException(InvalidArgumentException &&) = default;

                using LogicException::LogicException;

                virtual inline Code getDefaultCode() const noexcept { return 22; }
        };

        class DomainException: public LogicException
        {
            public:
                DomainException() = delete;
                DomainException(const DomainException &) = default;
                DomainException(DomainException &&) = default;

                using LogicException::LogicException;

                virtual inline Code getDefaultCode() const noexcept { return 33; }
        };

        class RangeException: public RuntimeException
        {
            public:
                RangeException() = delete;
                RangeException(const RangeException &) = default;
                RangeException(RangeException &&) = default;

                using RuntimeException::RuntimeException;

                virtual inline Code getDefaultCode() const noexcept { return 34; }
        };

        class NotImplementedException: public LogicException
        {
            public:
                NotImplementedException() = delete;
                NotImplementedException(const NotImplementedException &) = default;
                NotImplementedException(NotImplementedException &&) = default;

                using LogicException::LogicException;

                virtual inline Code getDefaultCode() const noexcept { return 38; }
        };

        class OverflowException: public RuntimeException
        {
            public:
                OverflowException() = delete;
                OverflowException(const OverflowException &) = default;
                OverflowException(OverflowException &&) = default;

                using RuntimeException::RuntimeException;

                virtual inline Code getDefaultCode() const noexcept { return 75; }
        };

        class NotSupportedException: public RuntimeException
        {
            public:
                NotSupportedException() = delete;
                NotSupportedException(const NotSupportedException &) = default;
                NotSupportedException(NotSupportedException &&) = default;

                using RuntimeException::RuntimeException;

                virtual inline Code getDefaultCode() const noexcept { return 95; }
        };

        /*
         * Exceptions that do not have an exact POSIX-compatible error code.
         * Sorted based on parent classes.
         */

        class UnderflowException: public RuntimeException
        {
            public:
                UnderflowException() = delete;
                UnderflowException(const UnderflowException &) = default;
                UnderflowException(UnderflowException &&) = default;

                using RuntimeException::RuntimeException;
        };

        class DivisionByZeroException: public ArithmeticException
        {
            public:
                DivisionByZeroException() = delete;
                DivisionByZeroException(const DivisionByZeroException &) = default;
                DivisionByZeroException(DivisionByZeroException &&) = default;

                using ArithmeticException::ArithmeticException;
        };

        class FileReadException: public IOException
        {
            public:
                FileReadException() = delete;
                FileReadException(const FileReadException &) = default;
                FileReadException(FileReadException &&) = default;

                using IOException::IOException;
        };

        class FileWriteException: public IOException
        {
            public:
                FileWriteException() = delete;
                FileWriteException(const FileWriteException &) = default;
                FileWriteException(FileWriteException &&) = default;

                using IOException::IOException;
        };
    }
}

#endif // GSLER_EXCEPTION_INC
