/*
** EPITECH PROJECT, 2019
** parser
** File description:
** cpp
*/

#include "Parser.hpp"
#include "Exception.hpp"

nts::Parser::Parser(std::vector<std::pair<std::string, std::string>> const &input)
{
    _type.push_back(std::make_pair(std::bind(&nts::Parser::isSpace, this, std::placeholders::_1),
                                   std::bind(&nts::Parser::put_section, this)));
    _type.push_back(std::make_pair(std::bind(&nts::Parser::isComponent, this, std::placeholders::_1),
                                   std::bind(&nts::Parser::put_component, this)));
    _type.push_back(std::make_pair(std::bind(&nts::Parser::isLink, this, std::placeholders::_1),
                                   std::bind(&nts::Parser::put_link, this)));
    creation(input);
}

void nts::Parser::input(std::string const &input)
{
    std::string container = input;
    size_t pos = container.find("#");
    if (pos != std::string::npos)
        container = container.substr(0, pos);
    if (container.find_first_not_of(" \t") != std::string::npos)
        _input.push_back(container);
}

void nts::Parser::parse(package_t &head)
{
    // RECURSIVE FUNCTION THAT CREATES AND LOAD INFORMATIONS OF THE TREE CREATED IN PARSER
//    std::cout << head.name << " => " << (int)head.type << std::endl;
    if (head.type == nts::Type::COMPONENT) {
        create_component(head);
        //std::cout << "Creating component\n";
    }
    else if (head.type == nts::Type::LINK) {
        // std::cout << "########################################\n";
        // std::cout << "head name =====================> " << head.name << std::endl;
        // std::cout << "########################################\n";
        //std::cout << "Creating link\n";
        create_link(head);
    }
    if ((*head.next)[0])
        parse(*((*head.next)[0]));
    if (!(*head.next)[0]) {
        for (auto curr : _outputs) {
            //std::cout << "process name => " << curr.first << std::endl;
            curr.second->compute();
        }
    }
}

nts::package_t *nts::Parser::start()
{
    package_t *ret = NULL;
    int i = 0;

    for (auto curr : _input) {
        ret = create_node(ret, curr);
    }
    return ret;
}

//==========================================================================================

nts::package_t *nts::Parser::init_node(package_t *node, std::string &token)
{
    node = new package_t(new std::vector<struct package_s *>);
    node->next->push_back(NULL);
    node->content = check_Value(token);
    node->name = check_Name(token);
    node->type = check_type(token);

    return node;
}

nts::package_t* nts::Parser::create_node(package_t *head, std::string &token)
{
    if (head != NULL) {
        if ((*head->next)[0])
            create_node((*head->next)[0], token);
        else
            (*head->next)[0] = init_node((*head->next)[0], token);
    }
    else
        head = init_node(head, token);
    return head;
}

nts::Type nts::Parser::check_type(std::string const &token) const
{
    std::string tok = token;
    size_t pos = tok.find_first_of(" \t");
    size_t idx = 0;

    if (_curr == ".chipsets:" && pos != std::string::npos) {
        tok = tok.substr(0, pos);
    }
    while (idx < _type.size() && !_type[idx].first(tok))
        idx++;
    if (idx < _type.size() && _type[idx].first(tok))
        return (_type[idx].second());
    throw (nts::LogicError("Error, " + tok + " is not a valid command."));
    return (nts::Type::UNUSED);
}

std::string nts::Parser::check_Value(std::string const &token) const
{
    std::string current;
    std::istringstream iterator(token);
    std::vector<std::string> block;

//    std::cout << "TOKEN => <" << token << ">" << std::endl;
    std::copy(std::istream_iterator<std::string>(iterator), std::istream_iterator<std::string>(), std::back_inserter(block));

    if (block.size() == 2) {
        if (block[0] == "input" || block[0] == "clock") {
            current = block[1];
            if (_inputValue.find(current) == _inputValue.end())
                throw (nts::InputError("Error, " + current + " is not initialized."));
            //std::cerr << "Error, " << current << " is not init" << std::endl;
            else
                return _inputValue.at(current);
        }
    }
    return "";
        
}
std::string nts::Parser::check_Name(std::string const &token)
{
    std::istringstream iterator(token);
    std::vector<std::string> block;

    std::copy(std::istream_iterator<std::string>(iterator), std::istream_iterator<std::string>(), std::back_inserter(block));
    if (block.size() == 2 && _cash.find(block[1]) != _cash.end())
        throw (nts::InputError("Error, double declaration of [" + block[1] + "]."));
    //std::cerr << "Error, double declaration of varible " << block[1] << std::endl;
    if (block.size() == 2 && isComponent(block[0]))
        _cash[block[1]] = block[0];
    return token;
}

bool nts::Parser::isSpace(std::string const &token)
{
    if (token == ".chipsets:" || token == ".links:") {
        _curr = token;
        return (true);
    }
    else
        return (false);
}

bool nts::Parser::isComponent(std::string const &token) const
{
    nts::MainComponent tester;
    IComponent *bol = tester.createComponent(token, "");
    if (bol == NULL) {
        delete (bol);
        return false;
    }
    else {
        delete (bol);;
        return true;
    }
}


bool nts::Parser::isLink(std::string const &token) const
{
    size_t first_point = 0;
    size_t second_point = 0;
    std::istringstream iterator(token);
    std::vector<std::string> block;

    std::copy(std::istream_iterator<std::string>(iterator), std::istream_iterator<std::string>(), std::back_inserter(block));
    if (block.size() != 2)
        return false;
    first_point = block[0].find(":");
    second_point = block[1].find(":");
    if (first_point == std::string::npos || second_point == std::string::npos)
        return false;
    return true;
}

bool nts::Parser::check_num(std::string const &str)
{
    for (size_t i = 0; i != str.size(); i++)
        if (!std::isdigit(str[i]))
            return false;
    return true;
}

nts::Type nts::Parser::put_section(void)
{
    return nts::Type::SECTION;
}

nts::Type nts::Parser::put_component()
{
    return nts::Type::COMPONENT;
}

nts::Type nts::Parser::put_link()
{
    return nts::Type::LINK;
}

void nts::Parser::creation(std::vector<std::pair<std::string, std::string>> const &input)
{
    for (auto curr : input)
        _inputValue[curr.first] = curr.second;
}

void nts::Parser::inverse()
{
    for (auto curr : _clocks)
        curr.second->inverse_value();
}

void nts::Parser::display() const
{
    for (auto curr : _outputs)
        std::cout << curr.first << "=" << curr.second->get_value() << std::endl;
}

void nts::Parser::dump() const
{
    for (auto curr : _components) {
//        std::cout << "component => " << curr.first << std::endl;
        std::cout << "name => " << curr.first << std::endl;
        curr.second->dump();
        std::cout << std::endl;
    }
}

void nts::Parser::change_input(std::string const &name, std::string const &value)
{
    if (_inputs.find(name) != _inputs.end()) {
        try {
            _inputs[name]->set_value(value);
        }
        catch (nts::InputError const &e) {
            throw (e);
        }
    }
    else
        throw (nts::InputError("Error, the target is not an input."));
}

void nts::Parser::create_component(package_t const &node)
{
    nts::MainComponent add;
    std::istringstream iterator(node.name);
    std::vector<std::string> block;

    std::copy(std::istream_iterator<std::string>(iterator), std::istream_iterator<std::string>(), std::back_inserter(block));
    if (block.size() != 2)
        return;
    if (_components.find(block[1]) != _components.end())
        return;

    _components[block[1]] = add.createComponent(block[0], node.content);
    //Super important : the dynamic cast returns a null pointer if fails to convert
    
    Output *output_target = dynamic_cast<Output *>(_components[block[1]]);
    Input *input_target = dynamic_cast<Input *>(_components[block[1]]);
    True *true_target = dynamic_cast<True *>(_components[block[1]]);
    False *false_target = dynamic_cast<False *>(_components[block[1]]);
    Clock *clock_target = dynamic_cast<Clock *>(_components[block[1]]);

    if (output_target)
        _outputs[block[1]] = output_target;
    if (input_target)
        _inputs[block[1]] = input_target;
    if (true_target)
        _trues[block[1]] = true_target;
    if (false_target)
        _flases[block[1]] = false_target;
    if (clock_target)
        _clocks[block[1]] = clock_target;
}

void nts::Parser::create_link(package_t const &node)
{
    std::string first_name;
    std::string second_name;
    std::string first_value;
    std::string second_value;
    size_t first_col;
    size_t second_col;
    std::istringstream iterator(node.name);
    std::vector<std::string> block;
    
    std::copy(std::istream_iterator<std::string>(iterator), std::istream_iterator<std::string>(), std::back_inserter(block));
    if (block.size() != 2)
        return;
    first_col = block[0].find_first_of(":");
    second_col = block[1].find_first_of(":");
    if (first_col == std::string::npos || second_col == std::string::npos)
        throw (nts::LogicError("Error, " + node.name + " is not a valid line."));
    first_name = block[0].substr(0, first_col);
    second_name = block[1].substr(0, second_col);
    first_value = block[0].substr(first_col + 1, block[0].size());
    second_value = block[1].substr(second_col + 1, block[1].size());
    if (!check_num(first_value) || !check_num(second_value))
        throw (nts::LogicError("Error, " + node.name + " contains a non numerical argument."));
    if (_components.find(first_name) == _components.end() || _components.find(second_name) == _components.end()) {
        throw (nts::LinkError("Error, " + first_name  + " is not declared."));
    }
//    std::cout << "FIRST NAME IS " << first_name << std::endl;
    //std::cout << "Verrification of the component\n";
    // for (auto it : _components) {
    //     std::cout << "ELEMENT NAME = " << it.first << std::endl;;
    //     it.second->dump();
    // }
    //std::cout << "Verrification done\n";
    _components[first_name]->setLink(std::stoi(first_value), *_components[second_name], std::stoi(second_value));
    //std::cout << "Operation done for the link setting\n";
}
