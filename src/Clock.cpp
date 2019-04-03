/*
** EPITECH PROJECT, 2019
** clock
** File description:
** cpp
*/

#include "Clock.hpp"
#include "Exception.hpp"

nts::Clock::Clock(std::string const &value)
{
    if (value == "0")
        _value = nts::Tristate::FALSE;
    else if (value == "1")
        _value = nts::Tristate::TRUE;
    else
        _value = nts::Tristate::UNDEFINED;
    _pin[0] = NULL;
    _link.first = 0;
    _link.second = 0;
}

nts::Clock::~Clock()
{
}

nts::Tristate nts::Clock::compute(std::size_t pin)
{
    if (pin - 1 > 0)
        throw (nts::PinError("Error, clock pin does not exists."));
    return _value;
}

void nts::Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin - 1 < 1 && _pin[pin - 1] == NULL) {
        _link.first = pin - 1;
        _link.second = otherPin;
        _pin[pin - 1] = &other;
        try {
        other.setLink(otherPin, *this, pin);
        }
        catch (nts::ChipsetError const &e) {
            throw (e);
        }
    }
    else if (pin - 1 < 0)
        throw (nts::PinError("Error, pin doesn't exists."));
}

void nts::Clock::dump() const
{
    std::cout << "##########Clock##########" << std::endl;
    if (_value == nts::Tristate::TRUE)
        std::cout << "value => " << "true" << std::endl;
    else if (_value == nts::Tristate::FALSE)
        std::cout << "value =>" << "false" << std::endl;
    else
        std::cout << "Undefined" << std::endl;
    if (_pin[0])
        std::cout << "pin1 is linked" << std::endl;
    else
        std::cout << "pin2 is not linked" << std::endl;
}

nts::Tristate nts::Clock::get_value() const
{
    return _value;
}

void nts::Clock::set_value(std::string const &value)
{
    if (value == "0")
        _value = nts::Tristate::FALSE;
    else if (value == "1")
        _value = nts::Tristate::TRUE;
    else {
        throw (nts::InputError("Error, clock value must be in [0, 1]."));
        _value = nts::Tristate::UNDEFINED;
    }
}

void nts::Clock::inverse_value()
{
    if (_value == nts::Tristate::FALSE)
        _value = nts::Tristate::TRUE;
    else if (_value == nts::Tristate::TRUE)
        _value = nts::Tristate::FALSE;
}
