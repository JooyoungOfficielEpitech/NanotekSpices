/*
** EPITECH PROJECT, 2019
** MainComponent.hpp
** File description:
** main for componnets
*/

#ifndef MAINCOMPONENT_H
#define MAINCOMPONENT_H

#include "Input.hpp"
#include "Output.hpp"
#include "Clock.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Port4018.hpp"
#include "Port4001.hpp"
#include "Port4008.hpp"
#include "Port4011.hpp"
#include "Port4013.hpp"
#include "Port4071.hpp"
#include "Port4030.hpp"
#include "Port4069.hpp"

#include <iostream>
#include "IComponent.hpp"
#include <string>
#include <vector>
#include <functional>
#include <map>

namespace nts
{
    class MainComponent
    {
    private:
        std::map<std::string, std::function<IComponent *(std::string const)>> _make;
        IComponent *create_input(std::string const &value);
        IComponent *create_clock(std::string const &value);
        IComponent *create_output(std::string const &value);
        IComponent *create_true(std::string const &value);
        IComponent *create_false(std::string const &value);
        IComponent *create_port4018(std::string const &value);
        IComponent *create_port4001(std::string const &value);
        IComponent *create_port4008(std::string const &value);
        IComponent *create_port4011(std::string const &value);
        IComponent *create_port4013(std::string const &value);
        IComponent *create_port4017(std::string const &value);
        IComponent *create_port4071(std::string const &value);
        IComponent *create_port4030(std::string const &value);
        IComponent *create_port4069(std::string const &value);
        IComponent *create_port4040(std::string const &value);
        IComponent *create_port4094(std::string const &value);
        IComponent *create_port4514(std::string const &value);
        IComponent *create_port4801(std::string const &value);
        IComponent *create_port2716(std::string const &value);
    public:
        MainComponent();
        ~MainComponent();

        IComponent *createComponent(std::string const &type, std::string const &value);
    };
}

#endif
