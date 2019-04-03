/*
** EPITECH PROJECT, 2019
** input
** File description:
** cpp
*/

#include "Input.hpp"
#include "Exception.hpp"

nts::Input::Input(std::string const &value)
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

nts::Input::~Input()
{
}

nts::Tristate nts::Input::compute(std::size_t pin)
{
    if (pin - 1 > 0)
        throw (nts::PinError("Error, input pin does not exists."));
    return _value;
}

void nts::Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
//    std::cout << "setlink for input is called\n";
    if (pin - 1 < 1 && _pin[pin - 1] == NULL) {
        _link.first = pin - 1;
        _link.second = otherPin;
        _pin[pin - 1] = &other;
//        other.dump();
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

void nts::Input::dump() const
{
    std::cout << "#############Input############" << std::endl;
    if (_value == nts::Tristate::TRUE)
        std::cout << "\tvalue => " << "true" << std::endl;
    else if (_value == nts::Tristate::FALSE)
        std::cout << "\tvalue =>" << "false" << std::endl;
    else
        std::cout << "\tUndefined" << std::endl;
    if (_pin[0])
        std::cout << "\tpin1 is linked" << std::endl;
    else
        std::cout << "\tpin1 is not linked" << std::endl;
}

nts::Tristate nts::Input::get_value() const
{
    return _value;
}

void nts::Input::set_value(std::string const &value)
{
    if (value == "0")
        _value = nts::Tristate::FALSE;
    else if (value == "1")
        _value = nts::Tristate::TRUE;
    else {
        throw (nts::InputError("Error, input value must be in [0, 1]."));
        _value = nts::Tristate::UNDEFINED;
    }
}
