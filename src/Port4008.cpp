/*
** EPITECH PROJECT, 2019
** prot
** File description:
** wja
*/

#include "Port4008.hpp"

nts::Port4008::Port4008(std::string const value)
{
    std::string target = value;
    std::function<Tristate(size_t)> use_input;
    std::function<Tristate(size_t)> use_output;

    for (size_t i = 0; i != 14; i++)
        _pin[i] = nullptr;
    use_input = std::bind(&nts::Port4008::doInput, this, std::placeholders::_1);
    use_output = std::bind(&nts::Port4008::doOutput, this, std::placeholders::_1);

    _execPin[1] = use_input;
    _execPin[2] = use_input;
    _execPin[3] = use_input;
    _execPin[4] = use_input;
    _execPin[5] = use_input;
    _execPin[6] = use_input;
    _execPin[7] = use_input;
    _execPin[15] = use_input;
    _execPin[9] = use_input;
    _execPin[10] = use_output;
    _execPin[11] = use_output;
    _execPin[12] = use_output;
    _execPin[13] = use_output;
    _execPin[14] = std::bind(&nts::Port4008::doContainer, this, std::placeholders::_1);

    _bridge[10] = std::make_pair(6, 7);
    _bridge[11] = std::make_pair(4, 5);
    _bridge[12] = std::make_pair(2, 3);
    _bridge[13] = std::make_pair(1, 15);
}

nts::Tristate nts::Port4008::compute(std::size_t pin)
{
    return _execPin[pin](pin);
}

void nts::Port4008::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin - 1 < 14 && _pin[pin - 1] == nullptr) {
        _link.insert(std::make_pair(pin - 1, otherPin));
        _pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    }
}


void nts::Port4008::dump() const
{
    std::cout << "##########PORT 4008###########" << std::endl;
    for (size_t i = 0; i != 16; i++) {
        std::cout << "\tNUNBER " << i + 1 << " ";
        if (_pin[i] == nullptr)
            std::cout << "value => (none)" << std::endl;
        else {
            std::cout << "value => ";
            std::cout << _pin[i]->compute(_link.at(i)) << std::endl;
        }
    }
}

nts::Tristate nts::Port4008::doInput(size_t pin)
{
    size_t real_pin = pin - 1;

    return (_pin[real_pin]->compute(_link.at(real_pin)));
}

nts::Tristate nts::Port4008::doOutput(size_t pin)
{
    size_t real_pin = pin - 1;
    nts::Tristate cont = nts::Tristate::FALSE;
    size_t one;
    size_t two;

    if (_bridge.find(pin) == _bridge.end())
        return (nts::Tristate::UNDEFINED);
    if (_pin[8])
        cont = _pin[8]->compute(_link.at(8));
    for (size_t i = 10; i <= pin; i++) {
        if (_bridge.find(i) != _bridge.end()) {
            one = _bridge.at(i).first - 1;
            two = _bridge.at(i).second - 1;
            if (_pin[one] && _pin[two])
                return (adderGate(_pin[one]->compute(_link.at(one)), _pin[two]->compute(_link.at(two)), cont));
        }
    }
    return (cont);
}

nts::Tristate nts::Port4008::doContainer(size_t pin)
{
    nts::Tristate def = nts::Tristate::FALSE;
    size_t one;
    size_t two;

    if (_pin[8])
        def = _pin[8]->compute(_link.at(8));
    for (size_t i = 10; i < pin; i++) {
        if (_bridge.find(i) != _bridge.end()) {
            one = _bridge.at(i).first - 1;
            two = _bridge.at(i).second - 1;
            if (_pin[one] && _pin[two])
                adderGate(_pin[one]->compute(_link.at(one)), _pin[two]->compute(_link.at(two)), def);
        }
    }    
    return (def);
}
        
nts::Tristate nts::Port4008::adderGate(nts::Tristate one, nts::Tristate two, nts::Tristate &container)
{
    int sum = (int)one + (int)two + (int)container;

    container = static_cast<nts::Tristate>(sum >> 1);
    return (static_cast<nts::Tristate>(sum & 1));
}
