#include "error-handler.hpp"

#include "exception.hpp"

using namespace Farsang;
using namespace Farsang::Exception;

bool ErrorHandler::toShowLocation = true;

// Umm... This is the magic!
const bool ErrorHandler::_prepare = ErrorHandler::prepare();

void ErrorHandler::handle(const Message message, const Path f, const Line l,
    const Code code)
{
    const Path file = ErrorHandler::toShowLocation ? f : nullptr;
    const Line line = ErrorHandler::toShowLocation ? l : Exception::Exception::LINE_UNKNOWN;

    switch (code) {
        // Will not enter here, but for making sure
        case GSL_SUCCESS:
            return;
            // No break

        case GSL_EDOM:
            throw DomainException(message, code, file, line);
            // No break

        case GSL_ERANGE:
            throw RangeException(message, code, file, line);
            // No break

        case GSL_EFAULT:
            throw InvalidPointerException(message, code, file, line);
            // No break

        case GSL_EINVAL:
            throw InvalidArgumentException(message, code, file, line);
            // No break

        case GSL_ENOMEM:
            throw OutOfMemoryException(message, code, file, line);
            // No break

        case GSL_EZERODIV:
            throw DivisionByZeroException(message, code, file, line);
            // No break

        case GSL_EUNDRFLW:
            throw UnderflowException(message, code, file, line);
            // No break

        case GSL_EOVRFLW:
            throw OverflowException(message, code, file, line);
            // No break

        case GSL_EUNSUP:
            throw NotSupportedException(message, code, file, line);
            // No break

        case GSL_EUNIMPL:
            throw NotImplementedException(message, code, file, line);
            // No break

        default:
            throw Exception::Exception(message, code, file, line);
            // No break
    }
}

bool ErrorHandler::prepare() noexcept(true)
{
    gsl_set_error_handler(&ErrorHandler::handle);

    // Non-sense
    return true;
}
