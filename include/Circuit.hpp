/*
** EPITECH PROJECT, 2019
** Circuit.hpp
** File description:
** circuit
*/

#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "Parser.hpp"
#include "IParser.hpp"
#include "IComponent.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

namespace nts
{
    class Circuit
    {
    private:
        std::string _filename; //used
        Parser *_parser; //declared
        package_t *_head; //used
    public:
        Circuit(std::string const &filename, std::vector<std::pair<std::string, std::string>> &av); //
        ~Circuit(); //
        void creation(); //
        void output() const; //
        void dump() const; //
        void inverse(); //
        void change_input(std::string const &name, std::string const &value); //
    };
}

#endif
