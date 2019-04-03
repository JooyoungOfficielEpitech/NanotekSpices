/*
** EPITECH PROJECT, 2019
** port4008
** File description:
** yes
*/

#ifndef PORT_4008
#define PORT_4008

#include "IComponent.hpp"

#include <iostream>
#include <functional>
#include <string>
#include <map>

namespace nts
{
    class Port4008 : public IComponent
    {
    private:
        IComponent * _pin[16];
        std::map<size_t, size_t> _link;
        std::map<size_t, std::function<Tristate(size_t)>> _execPin;
        std::map<size_t, std::pair<size_t, size_t>> _bridge;
    public:
        Port4008(std::string const value);

        virtual ~Port4008() = default;
        virtual nts::Tristate compute(std::size_t pin = 1);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        virtual void dump() const;

        nts::Tristate doInput(size_t pin);
        nts::Tristate doOutput(size_t pin);
        nts::Tristate doContainer(size_t pin);

        nts::Tristate adderGate(nts::Tristate one, nts::Tristate two, nts::Tristate &container);
    };
}

#endif
