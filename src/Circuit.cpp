/*
** EPITECH PROJECT, 2019
** circuit
** File description:
** cpp
*/

#include "Circuit.hpp"
#include "Exception.hpp"

nts::Circuit::Circuit(std::string const &filename,
                      std::vector<std::pair<std::string, std::string>> &av)
{
    std::string cursor = "";
    size_t pos = filename.find(".");

    if (pos == std::string::npos)
        throw (nts::FileError("Error, the filename is incorrect."));
    if (filename.substr(pos, filename.size()) != ".nts")
        throw (nts::FileError("Error, this is not a nts file."));
    std::ifstream content(filename.data());
    if (!content)
        throw (nts::FileError("Error, cannot open target file."));
    _head = nullptr;
    _parser = new Parser(av);
    try {
        while (std::getline(content, cursor)) {
            _parser->input(cursor);
        }
        _head = _parser->start();
    }
    catch (nts::NtsError const &e) {
        throw (e);
    }
}

nts::Circuit::~Circuit()
{
}

void nts::Circuit::creation()
{
    try {
        _parser->parse(*_head);
    }
    catch (nts::NtsError const &e){
        throw (e);
    }
}

void nts::Circuit::output() const
{
    _parser->display();
}

void nts::Circuit::dump() const
{
    _parser->dump();
}

void nts::Circuit::inverse()
{
    _parser->inverse();
}

void nts::Circuit::change_input(std::string const &name, std::string const &value)
{
    try {
        _parser->change_input(name, value);
    }
    catch (nts::NtsError const &e) {
        throw (e);
    }
}
