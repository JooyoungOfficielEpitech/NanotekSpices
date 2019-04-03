/*
** EPITECH PROJECT, 2019
** prot
** File description:
** wja
*/

#include "Port4013.hpp"

nts::Port4013::Port4013(std::string const value)
{
    std::string target = value;
    std::function<Tristate(size_t)> use_input;
    std::function<Tristate(size_t)> use_output;

    for (size_t i = 0; i != 14; i++)
        _pin[i] = nullptr;
    use_input = std::bind(&nts::Port4013::doInput, this, std::placeholders::_1);
    use_output = std::bind(&nts::Port4013::doOutput, this, std::placeholders::_1);

    _execPin[1] = use_input;
    _execPin[2] = use_input;
    _execPin[5] = use_input;
    _execPin[6] = use_input;
    _execPin[8] = use_input;
    _execPin[9] = use_input;
    _execPin[12] = use_input;
    _execPin[13] = use_input;
    _execPin[3] = use_output;
    _execPin[4] = use_output;
    _execPin[10] = use_output;
    _execPin[11] = use_output;

    _bridge[3] = std::make_pair(1, 2);
    _bridge[4] = std::make_pair(5, 6);
    _bridge[10] = std::make_pair(8, 9);
    _bridge[11] = std::make_pair(12, 13);
    std::cout << "No yet implementation\n";
}

nts::Tristate nts::Port4013::compute(std::size_t pin)
{
    return _execPin[pin](pin);
}

void nts::Port4013::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
//    std::cout << "Setlink for 4081\n";
//    std::cout << "pin => " << pin << " and otherPin => " << otherPin << std::endl;
    // for (size_t i = 0; i != 14; i++) {
    //     if (_pin[i] == NULL)
    //         std::cout << "pin[" << i << "] = NULL\n";
    //     else {
    //         std::cout << "pin[" << i << "] = " << _pin[i] << std::endl;
    //         _pin[i]->dump();
    //     }
    // }
//    std::cout << "pin vaut " << pin << std::endl;
    if (pin - 1 < 14 && _pin[pin - 1] == nullptr) {
//        std::cout << "in the Condition\n";
        _link.insert(std::make_pair(pin - 1, otherPin));
        _pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    }
}


void nts::Port4013::dump() const
{
    std::cout << "##########PORT 4013###########" << std::endl;
    for (size_t i = 0; i != 14; i++) {
        std::cout << "\tNUNBER " << i + 1 << " ";
        if (_pin[i] == nullptr)
            std::cout << "value => (none)" << std::endl;
        else {
            std::cout << "value => ";
            std::cout << _pin[i]->compute(_link.at(i)) << std::endl;
        }
    }
}

nts::Tristate nts::Port4013::doInput(size_t pin)
{
    size_t real_pin = pin - 1;

    return (_pin[real_pin]->compute(_link.at(real_pin)));
}

nts::Tristate nts::Port4013::doOutput(size_t pin)
{
    size_t real_pin = pin - 1;
    size_t one;
    size_t two;

    if (_bridge.find(pin) == _bridge.end())
        return (nts::Tristate::UNDEFINED);
    one = _bridge.at(pin).first - 1;
    two = _bridge.at(pin).second - 1;
    if (_pin[one] && _pin[two])
        return nandGate(_pin[one]->compute(_link.at(one)), _pin[two]->compute(_link.at(two)));
    return (nts::Tristate::UNDEFINED);
}


nts::Tristate nts::Port4013::nandGate(nts::Tristate one, nts::Tristate two)
{
    bool first = static_cast<bool>(one);
    bool second = static_cast<bool>(two);
    nts::Tristate result = static_cast<nts::Tristate>(!(first && second));

    return result;
}