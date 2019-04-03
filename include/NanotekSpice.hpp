/*
** EPITECH PROJECT, 2019
** include
** File description:
** main
*/

#ifndef _NANOTEKSPICE_H
#define _NANOTEKSPICE_H

#include "Circuit.hpp"
#include "IComponent.hpp"

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>

namespace nts
{
    class Nanotekspice
    {
    public:
        Nanotekspice(std::string const &filename, int const ac, char const **av); //
        ~Nanotekspice(); //
        void cmd(); //declared
    private:
        std::string _filename;
        int _ac; //declared
        bool _activate; //declared
        std::vector<std::pair<std::string, std::string>> _av; // put
        std::map<std::string, std::function<void(void)>> _cmd; //used
        nts::Circuit *_circuit;
        // bool forLoop;

        void exit(); //
        void display(); //
        void simulate(); //
        void loop(); //
        void dump(); //
        void setUp(std::string &s, size_t position); //
        std::string get_cmd(std::string &command); // 커맨드 공간 제거
    };

    void boom(int an);
}

#endif
