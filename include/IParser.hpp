/*
** EPITECH PROJECT, 2019
** interface
** File description:
** parser
*/

#ifndef IPARSER_H
#define IPARSER_H

#include <vector>
#include <string>

namespace nts
{
    enum class Type : int
    {
        UNUSED,
        NEWLINE,
        SECTION,
        COMPONENT,
        LINK,
        LINK_END,
        STRING
    };

    typedef struct package_s
    {
        package_s(std::vector<struct package_s *> *next) : next(next) {}
        std::vector<struct package_s *> *next;
        //struct package_s *next;
        std::string name;
        Type type;
        std::string content;
    }package_t;

    class IParser
    {
    public:
        virtual ~IParser() = default;
        virtual void input(std::string const &input) = 0;
        virtual void parse(package_t &head) = 0;
        virtual package_t *start() = 0; 
    };
}

#endif
