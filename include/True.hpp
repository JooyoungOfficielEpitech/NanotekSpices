/*
** EPITECH PROJECT, 2019
** true 
** File description:
** hpp
*/

#ifndef TRUE_H
#define TRUE_H

#include "IComponent.hpp"

#include <string>
#include <iostream>

namespace nts
{
    class True : public IComponent
    {
    private:
        nts::Tristate _value;
        IComponent *_pin[1];
        std::pair<size_t, size_t> _link;
    public:
        True();
        virtual ~True();
        virtual nts::Tristate compute(std::size_t pin = 1);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        virtual void dump() const;
        nts::Tristate get_value() const;
        void set_value(std::string const &value);
    };
}

#endif
