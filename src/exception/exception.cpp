#include "exception.hpp"

using namespace Gsler::Exception;

Exception::Exception(const Message &message):
    std::exception(),
    message(message)
{
}

Exception::Exception(const Message &message, const Code code):
    std::exception(),
    message(message),
    code(code)
{
}

Exception::Exception(const Message &message, const Location &location):
    std::exception(),
    message(message),
    path(location.path),
    line(location.line)
{
}

Exception::Exception(const Message &message, const Code code, const Location &location):
    std::exception(),
    message(message),
    path(location.path),
    line(location.line),
    code(code)
{
}

Exception::Exception(const Message &message, const Path &path, const Line line):
    std::exception(),
    message(message),
    path(path),
    line(line)
{
}

Exception::Exception(const Message &message, const Code code, const Path &path,
    const Line line):
    std::exception(),
    message(message),
    path(path),
    line(line),
    code(code)
{
}

const char *Exception::what() const noexcept
{
    // TODO: Implement this
}
