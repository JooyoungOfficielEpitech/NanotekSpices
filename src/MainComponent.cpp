/*
** EPITECH PROJECT, 2019
** main
** File description:
** component
*/

#include "MainComponent.hpp"

nts::MainComponent::MainComponent()
{
    _make.insert(std::make_pair("input", std::bind(&nts::MainComponent::create_input, this, std::placeholders::_1)));
    _make.insert(std::make_pair("output", std::bind(&nts::MainComponent::create_output, this, std::placeholders::_1)));
    _make.insert(std::make_pair("clock", std::bind(&nts::MainComponent::create_clock, this, std::placeholders::_1)));
    _make.insert(std::make_pair("true", std::bind(&nts::MainComponent::create_true, this, std::placeholders::_1)));
    _make.insert(std::make_pair("false", std::bind(&nts::MainComponent::create_false, this, std::placeholders::_1)));
    _make.insert(std::make_pair("4081", std::bind(&nts::MainComponent::create_port4018, this, std::placeholders::_1)));
    _make.insert(std::make_pair("4001", std::bind(&nts::MainComponent::create_port4001, this, std::placeholders::_1)));
    _make.insert(std::make_pair("4008", std::bind(&nts::MainComponent::create_port4008, this, std::placeholders::_1)));
     _make.insert(std::make_pair("4011", std::bind(&nts::MainComponent::create_port4011, this, std::placeholders::_1)));
     _make.insert(std::make_pair("4013", std::bind(&nts::MainComponent::create_port4013, this, std::placeholders::_1)));
     _make.insert(std::make_pair("4017", std::bind(&nts::MainComponent::create_port4017, this, std::placeholders::_1)));
     _make.insert(std::make_pair("4071", std::bind(&nts::MainComponent::create_port4071, this, std::placeholders::_1)));
     _make.insert(std::make_pair("4030", std::bind(&nts::MainComponent::create_port4030, this, std::placeholders::_1)));
     _make.insert(std::make_pair("4069", std::bind(&nts::MainComponent::create_port4069, this, std::placeholders::_1)));
     _make.insert(std::make_pair("4040", std::bind(&nts::MainComponent::create_port4040, this, std::placeholders::_1)));
     _make.insert(std::make_pair("4094", std::bind(&nts::MainComponent::create_port4094, this, std::placeholders::_1)));
     _make.insert(std::make_pair("4514", std::bind(&nts::MainComponent::create_port4514, this, std::placeholders::_1)));
     _make.insert(std::make_pair("4801", std::bind(&nts::MainComponent::create_port4801, this, std::placeholders::_1)));
     _make.insert(std::make_pair("2716", std::bind(&nts::MainComponent::create_port2716, this, std::placeholders::_1)));
}

nts::MainComponent::~MainComponent()
{
}

nts::IComponent *nts::MainComponent::create_input(std::string const &value)
{
    return (new Input(value));
}

nts::IComponent *nts::MainComponent::create_output(std::string const &value)
{
    std::string ho = value;
    
    return (new Output());
}

nts::IComponent *nts::MainComponent::create_clock(std::string const &value)
{
    return (new Clock(value));
}

nts::IComponent *nts::MainComponent::create_true(std::string const &value)
{
    std::string ho = value;

    return (new True());
}

nts::IComponent *nts::MainComponent::create_false(std::string const &value)
{
    std::string ho = value;

    return (new False());
}

nts::IComponent *nts::MainComponent::create_port4018(std::string const &value)
{
    return (new Port4018(value));
}

nts::IComponent *nts::MainComponent::create_port4001(std::string const &value)
{
    return (new Port4001(value));
}

nts::IComponent *nts::MainComponent::create_port4008(std::string const &value)
{
    return (new Port4008(value));
}


nts::IComponent *nts::MainComponent::create_port4011(std::string const &value)
{
    return (new Port4011(value));
}

nts::IComponent *nts::MainComponent::create_port4013(std::string const &value)
{
    std::cout << "No implementation of the port 4013" << std::endl;
    exit(0);
    return (new Port4013(value));
}

nts::IComponent *nts::MainComponent::create_port4017(std::string const &value)
{
    std::cout << "No implementation of the port 4017" << std::endl;
    exit(0);
    return (NULL);
}

nts::IComponent *nts::MainComponent::create_port4071(std::string const &value)
{
    return (new Port4071(value));
}

nts::IComponent *nts::MainComponent::create_port4030(std::string const &value)
{
    return (new Port4030(value));
}

nts::IComponent *nts::MainComponent::create_port4069(std::string const &value)
{
    return (new Port4069(value));
}

nts::IComponent *nts::MainComponent::create_port4040(std::string const &value)
{
    std::cout << "No implementation of the port 4040" << std::endl;
    exit(0);
    return (NULL);
}

nts::IComponent *nts::MainComponent::create_port4094(std::string const &value)
{
    std::cout << "No implementation of the port 4094" << std::endl;
    exit(0);
    return (NULL);
}

nts::IComponent *nts::MainComponent::create_port4514(std::string const &value)
{
    std::cout << "No implementation of the port 4514" << std::endl;
    exit(0);
    return (NULL);
}

nts::IComponent *nts::MainComponent::create_port4801(std::string const &value)
{
    std::cout << "No implementation of the port 4801" << std::endl;
    exit(0);
    return (NULL);
}

nts::IComponent *nts::MainComponent::create_port2716(std::string const &value)
{
    std::cout << "No implementation of the port 2716" << std::endl;
    exit(0);
    return (NULL);
}

nts::IComponent *nts::MainComponent::createComponent(std::string const &type, std::string const &value)
{
    if (_make.find(type) == _make.end()) {
        return nullptr;
    }
    return _make[type](value);
}

