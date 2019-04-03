/*
** EPITECH PROJECT, 2019
** false
** File description:
** cpp
*/

#include "False.hpp"
#include "Exception.hpp"

nts::False::False()
{
    _value = nts::Tristate::FALSE;
    _pin[0] = NULL;
    _link.first = 0;
    _link.second = 0;
}

nts::False::~False()
{
}

nts::Tristate nts::False::compute(std::size_t pin)
{
    if ((int)pin > 1)
        throw (nts::PinError("Error, false does not exists."));
    return _value;
}

void nts::False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
//    std::cout << "setlink for the false is called\n";
    if ((int)pin < 0 && _pin[pin - 1] == NULL) {
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
    else if ((int)pin < 0)
        throw (nts::PinError("Error, pin does not exists."));
}

void nts::False::dump() const
{
    std::cout << "##########False##########" << std::endl;
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

nts::Tristate nts::False::get_value() const
{
    return _value;
}

void nts::False::set_value(std::string const &value)
{
    if (value == "0")
        _value = nts::Tristate::FALSE;
    else if (value == "1")
        _value = nts::Tristate::TRUE;
    else
        throw (nts::InputError("Error, false must be in [0, 1]."));
}
