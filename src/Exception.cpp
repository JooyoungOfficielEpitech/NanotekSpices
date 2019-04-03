/*
** EPITECH PROJECT, 2019
** exception
** File description:
** cpp
*/

#include "Exception.hpp"

nts::NtsError::NtsError(std::string const &e) throw()
{
    _where = e;
}

nts::NtsError::NtsError() throw()
{
    _where = "";
}

nts::NtsError::~NtsError() throw()
{
}

const char *nts::NtsError::what() const throw()
{
    return _where.data();
}


nts::FileError::FileError(std::string const &content) throw() : NtsError(content)
{
}

nts::FileError::FileError() throw()
{
}

nts::FileError::~FileError() throw()
{
}


nts::LogicError::LogicError(std::string const &content) throw() : NtsError(content)
{
}

nts::LogicError::LogicError() throw()
{
}

nts::LogicError::~LogicError() throw()
{
}

nts::InputError::InputError(std::string const &content) throw() : NtsError(content)
{
}

nts::InputError::InputError() throw()
{
}

nts::InputError::~InputError() throw()
{
}


nts::OutputError::OutputError(std::string const &content) throw() : NtsError(content)
{
}

nts::OutputError::OutputError() throw()
{
}

nts::OutputError::~OutputError() throw()
{
}

nts::LinkError::LinkError(std::string const &content) throw() : NtsError(content)
{
}

nts::LinkError::LinkError() throw()
{
}

nts::LinkError::~LinkError() throw()
{
}


nts::PinError::PinError(std::string const &content) throw() : NtsError(content)
{
}

nts::PinError::PinError() throw()
{
}

nts::PinError::~PinError() throw()
{
}

nts::ChipsetError::ChipsetError(std::string const &content) throw() : NtsError(content)
{
}

nts::ChipsetError::ChipsetError() throw()
{
}

nts::ChipsetError::~ChipsetError() throw()
{
}
