#include "error-handler.hpp"

using namespace Gsler;

const bool ErrorHandler::_prepare = ErrorHandler::prepare();

void ErrorHandler::handle(const Message message, const FilePath file, const Line line,
    const ErrorCode code)
{
    // TODO: Implement this
}

bool ErrorHandler::prepare() noexcept(true)
{
    gsl_set_error_handler(&ErrorHandler::handle);

    // Non-sense
    return true;
}
