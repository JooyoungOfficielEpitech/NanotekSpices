/*
** EPITECH PROJECT, 2019
** clock 
** File description:
** hpp
*/

#ifndef CLOCK_H
#define CLOCK_H

#include "IComponent.hpp"

#include <string>
#include <iostream>

namespace nts
{
    class Clock : public IComponent
    {
    private:
        nts::Tristate _value;
        IComponent *_pin[1];
        std::pair<size_t, size_t> _link;
    public:
        Clock(std::string const &value);
        virtual ~Clock();
        virtual nts::Tristate compute(std::size_t pin = 1);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        virtual void dump() const;
        nts::Tristate get_value() const;
        void set_value(std::string const &value);
        void inverse_value();
    };
}

#endif
