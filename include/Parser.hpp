/*
** EPITECH PROJECT, 2019
** parser
** File description:
** cpp
*/

#ifndef PARSER_H
#define PARSER_H

#include "IParser.hpp"
#include "IComponent.hpp"
#include "MainComponent.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Clock.hpp"

#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <unordered_map>
#include <functional>
#include <iterator>

namespace nts
{
    class Parser : public IParser
    {
    private:
        
        //================================================================================
        // CREATION AND GESTION OF THE LINKED LIST VECTOR
        //================================================================================
        
        package_t *init_node(package_t *node, std::string &token);//
        package_t *create_node(package_t *head, std::string &token);//
        
        //================================================================================
        // VERRIFICATION OF CONTENT PER LINE
        //================================================================================
        
        Type check_type(std::string const &token) const;//
        std::string check_Value(std::string const &token) const;//
        std::string check_Name(std::string const &token);//

        std::vector<std::pair<std::function<bool(std::string const&)>,
                              std::function<Type()>>> _type; //defiend
        
        //================================================================================
        // BOOL FUNC THAT TELLS THE RIGHT TYPE OF THE LINE
        //================================================================================
        
        bool isSpace(std::string const &token); //
        bool isComponent(std::string const &token) const; //
        bool isLink(std::string const &token) const; //

        //================================================================================
        // EDITOR OF THE TYPE IN THE NODE
        //================================================================================
        
        Type put_section(void); //defined
        Type put_component(void); //defined
        Type put_link(void); //defined

        //================================================================================
        // CREATOR OF THE COMPONENT AND LINKS
        //================================================================================
        
        void create_component(package_t const &node); //
        void create_link(package_t const &node); //
        
        //================================================================================
        // TOOLS 
        //================================================================================
        
        bool check_num(std::string const &str); //defined

        //================================================================================
        // CONTAINERS OF ALL USEFUL INPUTS OF THE FILE
        //================================================================================
        
        std::vector<std::string> _input;
        std::string _curr;
        std::map<std::string, std::string> _cash;
        std::map<std::string, std::string> _inputValue;
        std::unordered_map<std::string, IComponent *> _components;
        std::map<std::string, Output *> _outputs;
        std::map<std::string, Input *> _inputs;
        std::map<std::string, True *> _trues;
        std::map<std::string, False *> _flases;
        std::map<std::string, Clock *> _clocks;
    public:
        Parser(std::vector<std::pair<std::string, std::string>> const &input); //defined
        virtual ~Parser() = default; //
        virtual void input(std::string const &input); // defined
        virtual void parse(package_t &head); //
        virtual package_t *start(); //defined

        void creation(std::vector<std::pair<std::string, std::string>> const &input); //define
        void inverse(); //
        void display() const; //
        void dump() const; //
        void change_input(std::string const &name, std::string const &value); //
    };
}

#endif
