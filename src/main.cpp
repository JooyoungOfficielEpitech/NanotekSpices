/*
** EPITECH PROJECT, 2019
** nanotek
** File description:
** main
*/

#include "NanotekSpice.hpp"
#include "Exception.hpp"
#include <iostream>

int main(int ac, const char **av)
{
  if (ac < 2) {
    std::cerr << "This is not a valid usage of the bin" << std::endl;
    return (0);
  }
  try {
      nts::Nanotekspice target(av[1], ac, av);// = new nts::Nanotekspice(av[1], ac, av);
      target.cmd();
  }
  catch(nts::NtsError const &e) {
      std::cerr << "Interruping program: " << e.what() << std::endl;
  }
  return (0);
}
