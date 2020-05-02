#include "exception.hpp"

using namespace Gsler;

Exception::Exception(const Message &message) noexcept(true):
    std::exception(),
    message(message)
{
}

Exception::Exception(const MessageString &message) noexcept(true):
    std::exception(),
    message(message)
{
}

Exception::Message Exception::what() const noexcept(true)
{
    return this->message.data();
}
