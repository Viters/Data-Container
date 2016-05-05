/**
* \file aghException.h
* \author Krzysztof Kaczor
* \date 15.04.2011
* \version 1.0
* \brief The definition of aghException class that allows for exception handling
*/
// -------------------------------------------------------------------------

#ifndef AGH_EXCEPTION
#define AGH_EXCEPTION
// --------------------------------------------------------------

#include <iostream>
#include <string.h>

using namespace std;

// --------------------------------------------------------------

/**
* \class aghException
* \author Krzysztof Kaczor
* \date 15.04.2011
* \brief The definition of aghException class that allows for exception handling
*/
class aghException
{
  private:

    int _errorCode;         ///< Stores an error code
    int _errorLine;         ///< Stores an error line (in the file)
    string _errorMessage;    ///< Stores an error message (for the user)
    string _errorFile;       ///< Stores a name of the file where an error occured

    /// \brief resets the error parameters
    ///
    /// \return no values returns
    void reset(void);

  public:

    /// \brief The default constructor
    aghException(void);

    /// \brief The copying constructor
    ///
    /// \param __other - the source object
    aghException(aghException const &__other);

    /// \brief The class contructor
    ///
    /// \param __errorCode - code of the error
    /// \param __errorLine - line (in the file) where the error occured
    aghException(int __errorCode, int __errorLine);

    /// \brief The class contructor
    ///
    /// \param __errorCode - code of the error
    /// \param __errorMessage - the error message for the user
    aghException(int __errorCode, string __errorMessage);

    /// \brief The class constructor
    ///
    /// \param __errorFile - the name of the file where the error occured
    /// \param __errorLine - the line in the file where the error occured
    aghException(string __errorFile, int __errorLine);

    /// \brief The class constructor
    ///
    /// \param __errorCode - code of the error
    /// \param __errorMessage - the error message for the user
    /// \param __errorFile - the name of the file where the error occured
    /// \param __errorLine - the line in the file where the error occured
    aghException(int __errorCode, string __errorMessage, string __errorFile, int __errorLine);

    /// \brief The class destructor
    virtual ~aghException(void);

    /// \brief Virtual function that returns the error code
    ///
    /// \return a value of the _errorCode field
    virtual int errorCode(void) const;

    /// \brief Virtual function that returns the line in the file where the error occured
    ///
    /// \return a value of the _errorLine field
    virtual int errorLine(void) const;

    /// \brief Virtual function that returns the error message for a user
    ///
    /// \return a value of the _errorMessage field
    virtual string errorMessage(void) const;

    /// \brief Virtual function that returns the error file name
    ///
    /// \return a value of the _errorFile field
    virtual string errorFile(void) const;

    /// \brief Virtual function that sets the error line number
    ///
    /// \param __errorLine - a new value of the _errorLine field
    /// \return no values return
    virtual void setErrorLine(int __errorLine);

    /// \brief Virtual function that sets the error code
    ///
    /// \param __errorCode - a new value of the _errorCode field
    /// \return no values return
    virtual void setErrorCode(int __errorCode);

    /// \brief Virtual function that sets the error message
    ///
    /// \param __errorMessage - a new value of the _errorMessage field
    /// \return no values return
    virtual void setErrorMessage(string __errorMessage);

    /// \brief Virtual function that sets the error file name
    ///
    /// \param __errorFile - a new value of the _errorFile field
    /// \return no values return
    virtual void setErrorFile(string __errorFile);

    /// \brief Assigments operator
    ///
    /// \param __other - the source object
    /// \return reference to this object
    aghException &operator=(aghException const &__other);
};
// --------------------------------------------------------------

/// \brief an overloaded operator << that writes the error parameters to the given stream
///
/// \param __out - a given stream (display, file, etc.)
/// \param __exception - a reference to the exception object
/// \return returns a reference to the given stream
ostream &operator<<(ostream &__out, aghException &__exception);
// --------------------------------------------------------------

#endif
