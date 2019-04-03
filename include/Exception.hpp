/*
** EPITECH PROJECT, 2019
** exception
** File description:
** hp
*/

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <exception>

namespace nts
{
    class NtsError : public std::exception
    {
    private:
        std::string _where;
    public:
        NtsError(std::string const &e) throw();
        NtsError() throw();
        virtual ~NtsError() throw();
        virtual const char *what() const throw();
    };

    class FileError : public NtsError
    {
    public:
        FileError(std::string const& content) throw();
        FileError() throw();
        virtual ~FileError() throw();
    };

    class LogicError : public NtsError
    {
    public:
        LogicError(std::string const& content) throw();
        LogicError() throw();
        virtual ~LogicError() throw();
    };

    class InputError : public NtsError
    {
    public:
        InputError(std::string const& content) throw();
        InputError() throw();
        virtual ~InputError() throw();
    };

    class OutputError : public NtsError
    {
    public:
        OutputError(std::string const& content) throw();
        OutputError() throw();
        virtual ~OutputError() throw();
    };

    class LinkError : public NtsError
    {
    public:
        LinkError(std::string const& content) throw();
        LinkError() throw();
        virtual ~LinkError() throw();
    };

    class PinError : public NtsError
    {
    public:
        PinError(std::string const& content) throw();
        PinError() throw();
        virtual ~PinError() throw();
    };

    class ChipsetError : public NtsError
    {
    public:
        ChipsetError(std::string const& content) throw();
        ChipsetError() throw();
        virtual ~ChipsetError() throw();
    };
}

#endif
