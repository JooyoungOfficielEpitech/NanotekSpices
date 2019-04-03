/*
** EPITECH PROJECT, 2019
** port4071
** File description:
** yes
*/

#ifndef PORT_4071
#define PORT_4071

#include "IComponent.hpp"

#include <iostream>
#include <functional>
#include <string>
#include <map>

namespace nts
{
    class Port4071 : public IComponent
    {
    private:
        IComponent * _pin[14];
        std::map<size_t, size_t> _link;
        std::map<size_t, std::function<Tristate(size_t)>> _execPin;
        std::map<size_t, std::pair<size_t, size_t>> _bridge;
    public:
        Port4071(std::string const value);

        virtual ~Port4071() = default;
        virtual nts::Tristate compute(std::size_t pin = 1);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        virtual void dump() const;

        nts::Tristate doInput(size_t pin);
        nts::Tristate doOutput(size_t pin);

        nts::Tristate orGate(nts::Tristate one, nts::Tristate two);
    };
}

#endif
