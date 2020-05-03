#include "exception.hpp"

using namespace Gsler::Exception;

const Exception::Path Exception::PATH_UNKNOWN = nullptr;
const Exception::Line Exception::LINE_UNKNOWN = -1;
const Exception::Code Exception::CODE_UNKNOWN = 0;

const char *Exception::WHERE_UNKNOWN = nullptr;

Exception::Exception(const Message &message):
    std::exception(),
    message(message)
{
    this->prepare();
}

Exception::Exception(const Message &message, const Code code):
    std::exception(),
    message(message),
    code(code)
{
    this->prepare();
}

Exception::Exception(const Message &message, const Path path, const Line line):
    std::exception(),
    message(message),
    path(path),
    line(line)
{
    this->prepare();
}

Exception::Exception(const Message &message, const Code code, const Path path,
    const Line line):
    std::exception(),
    message(message),
    path(path),
    line(line),
    code(code)
{
    this->prepare();
}

const char *Exception::what() const noexcept
{
    return this->whatStr.empty() ? this->message.c_str() : this->whatStr.c_str();
}

const char *Exception::where() const noexcept
{
    return this->whereStr.empty() ? Exception::WHERE_UNKNOWN : this->whereStr.c_str();
}

const char *Exception::getMessage() const noexcept
{
    return this->message.c_str();
}

const char *Exception::getPath() const noexcept
{
    return this->path;
}

Exception::Line Exception::getLine() const noexcept
{
    return this->line;
}

Exception::Code Exception::getCode() const noexcept
{
    return this->code == Exception::CODE_UNKNOWN ? this->getDefaultCode() : this->code;
}

bool Exception::hasPath() const noexcept
{
    return this->path != Exception::PATH_UNKNOWN;
}

bool Exception::hasLine() const noexcept
{
    return this->line != Exception::LINE_UNKNOWN;
}

bool Exception::hasWhere() const noexcept
{
    return this->where() != Exception::WHERE_UNKNOWN;
}

void Exception::prepareWhere()
{
    // Make sure the function will call only once
    static bool called = false;
    if (called) {
        return;
    }

    this->whereStr = "";
    if (this->hasPath()) {
        this->whereStr = this->whereStr + "in file '" + this->path + "'";
        if (this->hasLine()) {
            this->whereStr = this->whereStr + " at line " + std::to_string(this->line);
        }
    }

    called = true;
}

void Exception::prepareWhat()
{
    // Make sure the function will call only once
    static bool called = false;
    if (called) {
        return;
    }

    this->prepareWhere();

    this->whatStr = this->message;
    if (this->hasWhere()) {
        this->whatStr = this->whatStr + " (" + this->whereStr + ")";
    }

    called = true;
}
