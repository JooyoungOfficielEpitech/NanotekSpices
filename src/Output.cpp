/*
** EPITECH PROJECT, 2019
** output
** File description:
** cpp
*/

#include "Output.hpp"
#include "Exception.hpp"

nts::Output::Output()
{
    _value = nts::Tristate::UNDEFINED;
    _pin[0] = NULL;
    _link.first = 0;
    _link.second = 0;
}

nts::Output::~Output()
{
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
    if (pin - 1 > 0)
        throw (nts::PinError("Error, pin does not exists."));
    if (_pin[0] == NULL)
        throw (nts::OutputError("Error, output has no link."));
    _value = _pin[pin - 1]->compute(_link.second);
    return _value;
}

void nts::Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    // std::cout << "setlink for output is called\n";
    // std::cout << "pin vaut " << pin << std::endl;
    if (pin - 1 < 1 && _pin[pin - 1] == NULL) {
//        std::cout << "I AM HERE MOTHER FUCKERS\n";
        _link.first = pin - 1;
        _link.second = otherPin;
        _pin[0] = &other;
        try {
            other.setLink(otherPin, *this, pin);
        }
        catch (nts::ChipsetError const &e) {
            throw (e);
        }
    }
    else if ((int)pin < 0)
        throw (nts::PinError("Error, no existing pin."));
}

void nts::Output::dump() const
{
    std::cout << "############Output############" << std::endl;
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

nts::Tristate nts::Output::get_value() const
{
    return _value;
}
