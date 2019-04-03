/*
** EPITECH PROJECT, 2019
** Nanotek
** File description:
** class creator
*/

#include <string>
#include <iostream>
#include "NanotekSpice.hpp"
#include "Exception.hpp"
#include <csignal>

bool loopState;

nts::Nanotekspice::Nanotekspice(std::string const &filename, int const ac, char const **av)
{
    std::string cursor = "";
    std::string expected_value = "";
    size_t pos;

    _filename = filename;
    _ac = ac;
    _activate = true;
    _cmd["exit"] = std::bind(&nts::Nanotekspice::exit, this);
    _cmd["display"] = std::bind(&nts::Nanotekspice::display, this);
    _cmd["simulate"] = std::bind(&nts::Nanotekspice::simulate, this);
    _cmd["loop"] = std::bind(&nts::Nanotekspice::loop, this);
    _cmd["dump"] = std::bind(&nts::Nanotekspice::dump, this);

    //================================================================================
    // CHECK THE AV VALUES OF THE BIN
    //================================================================================

    for (int i = 2; i < ac; i++) {
        cursor = av[i];
        pos = cursor.find("=");
        if (pos != std::string::npos) {
            expected_value = cursor.substr(pos + 1, cursor.size());
            if (expected_value == "1" || expected_value == "0")
                _av.push_back(std::make_pair(cursor.substr(0, pos), expected_value));
            else
                throw (nts::InputError("Error, input is not 1 or 0."));
        }
    }
    try {
    _circuit = new nts::Circuit(filename, _av);
    }
    catch (nts::NtsError const &e) {
        throw (e);
    }
}

nts::Nanotekspice::~Nanotekspice()
{
}

void nts::Nanotekspice::cmd()
{
    std::string line;

    try {
        simulate();
        display();
    }
    catch (nts::NtsError const &e) {
        throw(e);
    }
    std::cout << "> ";
    while ( _activate && std::getline(std::cin, line)) {
        line = get_cmd(line);
        if (_cmd.find(line) != _cmd.end()) {
            _cmd[line]();
        }
        else if (line.find("=") != std::string::npos) {
            setUp(line, line.find("="));
        }
        else if (line.size() > 0)
            std::cout << "Error, command not found." << std::endl;
        if (_activate)
            std::cout << "> ";
    }
}

void nts::Nanotekspice::exit()
{
    _activate = false;
}

void nts::Nanotekspice::display()
{
    _circuit->output();
}

void nts::Nanotekspice::simulate()
{
    _circuit->creation();
    _circuit->inverse();
}

void nts::Nanotekspice::loop()
{
    loopState = true;
    signal(SIGINT, boom);
    while (loopState) {
        simulate();
        std::cout << "h\n";
    }
}

void nts::Nanotekspice::dump()
{
    _circuit->dump();
}

void nts::Nanotekspice::setUp(std::string &command, size_t position)
{
    std::string one = command.substr(0, position);
    std::string two = command.substr(position + 1, command.size());

    if (_circuit) {
        try {
            _circuit->change_input(one, two);
        }
        catch (nts::NtsError const &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

std::string nts::Nanotekspice::get_cmd(std::string &command)
{
    std::string result = "";
    std::istringstream tool(command);
    std::vector<std::string> token;
    
    std::copy(std::istream_iterator<std::string>(tool),
              std::istream_iterator<std::string>(),
              std::back_inserter(token));
    for (size_t i = 0 ; i < token.size() ; i++)
    {
        result += token[i];
        if (i + 1 < token.size())
            result += " ";
    }
    return result;
}

void nts::boom(int an)
{
    (void) an;
    std::cout << "vibrei\n";
    loopState = false;
}
