/*
filename: main.cpp

This code simulates the PD microcircuit model (Potjans and Diesmann, 2014)
with the GL (Galves and Locherbach, 2013) neuron in discrete time.

This code is part of STENDHAL package.
A NeuroMat package for simulate neuron networks, and analyse data.

Director:
Antonio Galves

Developers:
Nilton L. Kamiji
Christophe Pouzat
Renan Shimoura

Contributors:
Karine Guimaraes
Aline Duarte
Jorge Stolfi
Antonio Roque

Aug 11, 2020
*/

// Include C++ standard headers
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <cmath>
#include <random>
#include <chrono>

// Include pcg if compiled with -D USE_PCG
#ifdef USE_PCG
#include "pcg-cpp/pcg_random.hpp"
#endif

// Include stendhal headers
//#include "stendhalconfig.h"
#include "dPD_GL.hpp"
#include "gl_psc_exp.hpp"

/* Filename: main_dPD_GL.cpp
main function

*/

int main ( int argc, char* argv[] )
{
  class stendhal::dPD_GL dpd_gl;

  auto start = std::chrono::steady_clock::now();
  dpd_gl.calibrate();
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> diff = end-start;
  std::cout << "calibrate: " << diff.count() << " s\n";

  start = std::chrono::steady_clock::now();
  dpd_gl.create_pop();
  end = std::chrono::steady_clock::now();
  diff = end-start;
  std::cout << "create_pop: " << diff.count() << " s" << std::endl;

  start = std::chrono::steady_clock::now();
  dpd_gl.connect();
  end = std::chrono::steady_clock::now();
  diff = end-start;
  std::cout << "connect: " << diff.count() << " s" << std::endl;

  start = std::chrono::steady_clock::now();
  double t_sim = 1000.0;
  dpd_gl.simulate(t_sim);
  end = std::chrono::steady_clock::now();
  diff = end-start;
  std::cout << "simulate(" << t_sim << "): " << diff.count() << " s" << std::endl;
  
  return 0;
} 