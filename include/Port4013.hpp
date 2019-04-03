/*
** EPITECH PROJECT, 2019
** port4013
** File description:
** yes
*/

#ifndef PORT_4013
#define PORT_4013

#include "IComponent.hpp"

#include <iostream>
#include <functional>
#include <string>
#include <map>

namespace nts
{
    class Port4013 : public IComponent
    {
    private:
        IComponent * _pin[14];
        std::map<size_t, size_t> _link;
        std::map<size_t, std::function<Tristate(size_t)>> _execPin;
        std::map<size_t, std::pair<size_t, size_t>> _bridge;
    public:
        Port4013(std::string const value);

        virtual ~Port4013() = default;
        virtual nts::Tristate compute(std::size_t pin = 1);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        virtual void dump() const;

        nts::Tristate doInput(size_t pin);
        nts::Tristate doOutput(size_t pin);

        nts::Tristate nandGate(nts::Tristate one, nts::Tristate two);
    };
}

#endif
