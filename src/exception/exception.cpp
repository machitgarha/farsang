#include "exception.hpp"

using namespace Gsler::Exception;

Exception::Exception(const Message &message):
    std::exception(),
    message(message)
{
}

const char *Exception::what() const noexcept
{
    return this->message.data();
}
