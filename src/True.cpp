/*
** EPITECH PROJECT, 2019
** true
** File description:
** cpp
*/

#include "True.hpp"
#include "Exception.hpp"

nts::True::True()
{
    _value = nts::Tristate::TRUE;
    _pin[0] = NULL;
    _link.first = 0;
    _link.second = 0;
}

nts::True::~True()
{
}

nts::Tristate nts::True::compute(std::size_t pin)
{
    if (pin > 1)
        throw (nts::PinError("Error,  true pin does not exits."));
    return _value;
}

void nts::True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
//    std::cout << "setLink for the true is called\n";
    // for (size_t i = 0; i != 1; i++) {
    //     if (_pin[i] == NULL)
    //         std::cout << "pin[" << i << "] = NULL\n";
    //     else {
    //         std::cout << "pin[" << i << "] = " << _pin[i] << std::endl;
    //         _pin[i]->dump();
    //     }
    // }
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
    else if ((int)pin < 0)
        throw (nts::PinError("Error, pin does not exists."));
}

void nts::True::dump() const
{
    std::cout << "#############True#############" << std::endl;
    if (_value == nts::Tristate::TRUE)
        std::cout << "\tvalue => " << "true" << std::endl;
    else if (_value == nts::Tristate::FALSE)
        std::cout << "\tvalue =>" << "false" << std::endl;
    else
        std::cout << "\tUndefined" << std::endl;
    if (_pin[0]) {
        std::cout << "\tpin1 is linked" << std::endl;
    }
    else
        std::cout << "\tpin1 is not linked" << std::endl;
}

nts::Tristate nts::True::get_value() const
{
    return _value;
}

void nts::True::set_value(std::string const &value)
{
    if (value == "0")
        _value = nts::Tristate::FALSE;
    else if (value == "1")
        _value = nts::Tristate::TRUE;
    else
        throw (nts::InputError("Error, true must be in [0, 1]."));
}
