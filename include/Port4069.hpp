/*
** EPITECH PROJECT, 2019
** port4069
** File description:
** yes
*/

#ifndef PORT_4069
#define PORT_4069

#include "IComponent.hpp"

#include <iostream>
#include <functional>
#include <string>
#include <map>

namespace nts
{
    class Port4069 : public IComponent
    {
    private:
        IComponent * _pin[14];
        std::map<size_t, size_t> _link;
        std::map<size_t, std::function<Tristate(size_t)>> _execPin;
        std::map<size_t, size_t> _bridge;
    public:
        Port4069(std::string const value);

        virtual ~Port4069() = default;
        virtual nts::Tristate compute(std::size_t pin = 1);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        virtual void dump() const;

        nts::Tristate doInput(size_t pin);
        nts::Tristate doOutput(size_t pin);

        nts::Tristate notGate(nts::Tristate one);
    };
}

#endif
