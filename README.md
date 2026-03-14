# Poker Probability Simulator

A Monte Carlo simulation written in C++ to estimate probabilities of 5-card poker hands.

## Features

* Simulates poker hands using random sampling
* Detects all 9 poker hand types
* Compares simulated probabilities with theoretical probabilities
* Calculates error
* Measures runtime performance
* Demonstrates Monte Carlo convergence

## Monte Carlo Convergence

Simulations are performed with increasing sample sizes:

1000 -> 10000 -> 100000 -> 1000000 -> 10000000

As the number of simulations increases, the simulated probabilities approach the theoretical probabilities, demonstrating **Monte Carlo convergence** and the **Law of Large Numbers**.

## Project Structure

poker-probability-simulator/
|
|-- main.cpp
|-- README.md

## Language

C++

## Author

Hitansh Aggarwal
