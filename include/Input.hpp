/*
** EPITECH PROJECT, 2019
** input 
** File description:
** hpp
*/

#ifndef INPUT_H
#define INPUT_H

#include "IComponent.hpp"

#include <string>
#include <iostream>

namespace nts
{
    class Input : public IComponent
    {
    private:
        nts::Tristate _value;
        IComponent *_pin[1];
        std::pair<size_t, size_t> _link;
    public:
        Input(std::string const &value);
        virtual ~Input();
        virtual nts::Tristate compute(std::size_t pin = 1);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        virtual void dump() const;
        nts::Tristate get_value() const;
        void set_value(std::string const &value);
    };
}

#endif
