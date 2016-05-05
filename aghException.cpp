#include <iostream>
#include <string.h>
// --------------------------------------------------------------

using namespace std;
// --------------------------------------------------------------

#include "aghException.h"
// --------------------------------------------------------------

aghException::aghException(void)
{
    reset();
}
// --------------------------------------------------------------

aghException::aghException(aghException const &__other)
{
    reset();
    setErrorCode(__other.errorCode());
    setErrorLine(__other.errorLine());
    setErrorMessage(__other.errorMessage());
    setErrorFile(__other.errorFile());
}
// --------------------------------------------------------------

aghException::aghException(int __errorCode, int __errorLine)
{
    reset();
    setErrorCode(__errorCode);
    setErrorLine(__errorLine);
}
// --------------------------------------------------------------

aghException::aghException(int __errorCode, string __errorMessage)
{
    reset();
    setErrorCode(__errorCode);
    setErrorMessage(__errorMessage);
}
// --------------------------------------------------------------

aghException::aghException(string __errorFile, int __errorLine)
{
    reset();
    setErrorLine(__errorLine);
    setErrorFile(__errorFile);
}
// --------------------------------------------------------------

aghException::aghException(int __errorCode, string __errorMessage, string __errorFile, int __errorLine)
{
    reset();
    setErrorCode(__errorCode);
    setErrorLine(__errorLine);
    setErrorMessage(__errorMessage);
    setErrorFile(__errorFile);
}
// --------------------------------------------------------------

aghException::~aghException(void)
{
    reset();
}
// --------------------------------------------------------------

void aghException::reset(void)
{
    _errorMessage = "";
    _errorFile = "";
    _errorLine = -1;
    _errorCode = -1;
}
// --------------------------------------------------------------

int aghException::errorCode(void) const
{
    return _errorCode;
}
// --------------------------------------------------------------

int aghException::errorLine(void) const
{
    return _errorLine;
}
// --------------------------------------------------------------

string aghException::errorMessage(void) const
{
    return _errorMessage;
}
// --------------------------------------------------------------

string aghException::errorFile(void) const
{
    return _errorFile;
}
// --------------------------------------------------------------

void aghException::setErrorLine(int __errorLine)
{
    _errorLine = __errorLine;
}
// --------------------------------------------------------------

void aghException::setErrorCode(int __errorCode)
{
    _errorCode = __errorCode;
}
// --------------------------------------------------------------

void aghException::setErrorMessage(string __errorMessage)
{
    _errorMessage = __errorMessage;
}
// --------------------------------------------------------------

void aghException::setErrorFile(string __errorFile)
{
    _errorFile = __errorFile;
}
// --------------------------------------------------------------

aghException &aghException::operator=(aghException const &__other)
{
    reset();

    setErrorCode(__other.errorCode());
    setErrorLine(__other.errorLine());
    setErrorMessage(__other.errorMessage());
    setErrorFile(__other.errorFile());

    return *this;
}
// --------------------------------------------------------------

ostream &operator<<(ostream &__out, aghException &__exception)
{
    __out << "Error in " << __exception.errorFile() << " file at " << __exception.errorLine() << " line.\nError code: " << __exception.errorCode() << " (" << __exception.errorMessage() << ").";
    return __out;
}
// --------------------------------------------------------------
