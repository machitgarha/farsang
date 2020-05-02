#include "exception.hpp"

using namespace Gsler::Exception;

Exception::Exception(const Message &message) noexcept(true):
    std::exception(),
    message(message)
{
}

const char *Exception::what() const noexcept(true)
{
    return this->message.data();
}
