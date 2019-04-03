/*
** EPITECH PROJECT, 2019
** I
** File description:
** interface of the component
*/

#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include <string>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
    public:
        virtual ~IComponent() = default;
    public:
        //?? std::size_t ????
        virtual nts::Tristate compute(std::size_t pin = 1) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        virtual void dump() const = 0;
    };
}

#endif
