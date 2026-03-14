# Poker Probability Simulator

A Monte Carlo simulation written in C++ to estimate probabilities of 5-card poker hands.

## Features

* Simulates poker hands using random sampling
* Detects all 9 poker hand types
* Compares simulated probabilities with theoretical probabilities
* Calculates error
* Measures runtime performance
* Demonstrates Monte Carlo convergence

## Concepts Used

- Monte Carlo Simulation
- Monte Carlo Convergence
- Probability Theory
- Random Number Generation (mt19937)
- Law of Large Numbers
- C++ STL

## Example Output

Total Simulations:  1000

-----------------------------------------------------------
Hand              Simulated    Theoretical  Error

Straight Flush:   0 1.39e-05 1.39e-05
Four of a Kind:   0 0.00024 0.00024
Full House:       0.001 0.001441 0.000441
Flush:            0 0.001965 0.001965
Straight:         0.001 0.003925 0.002925
Three of a Kind:  0.025 0.021128 0.003872
Two Pair:         0.05 0.047539 0.002461
Pair:             0.427 0.422569 0.00443098
High Card:        0.496 0.501177 0.00517702
-----------------------------------------------------------

Runtime: 1 ms



Total Simulations:  10000

-----------------------------------------------------------
Hand              Simulated    Theoretical  Error

Straight Flush:   0.0001 1.39e-05 8.61e-05
Four of a Kind:   0.0001 0.00024 0.00014
Full House:       0.0018 0.001441 0.000359
Flush:            0.0018 0.001965 0.000165
Straight:         0.0033 0.003925 0.000625
Three of a Kind:  0.021 0.021128 0.000128001
Two Pair:         0.0479 0.047539 0.000360999
Pair:             0.4153 0.422569 0.007269
High Card:        0.5087 0.501177 0.007523
-----------------------------------------------------------

Runtime: 15 ms



Total Simulations:  100000

-----------------------------------------------------------
Hand              Simulated    Theoretical  Error

Straight Flush:   3e-05 1.39e-05 1.61e-05
Four of a Kind:   0.00024 0.00024 0
Full House:       0.00128 0.001441 0.000161
Flush:            0.00217 0.001965 0.000205
Straight:         0.00372 0.003925 0.000205
Three of a Kind:  0.02224 0.021128 0.001112
Two Pair:         0.04854 0.047539 0.001001
Pair:             0.41832 0.422569 0.00424901
High Card:        0.50346 0.501177 0.00228298
-----------------------------------------------------------

Runtime: 69 ms



Total Simulations:  1000000

-----------------------------------------------------------
Hand              Simulated    Theoretical  Error

Straight Flush:   1e-05 1.39e-05 3.9e-06
Four of a Kind:   0.000228 0.00024 1.2e-05
Full House:       0.001531 0.001441 9e-05
Flush:            0.002052 0.001965 8.7e-05
Straight:         0.003885 0.003925 3.99998e-05
Three of a Kind:  0.020727 0.021128 0.000401001
Two Pair:         0.047722 0.047539 0.000183001
Pair:             0.422482 0.422569 8.6993e-05
High Card:        0.501363 0.501177 0.000185966
-----------------------------------------------------------

Runtime: 510 ms



Total Simulations:  10000000

-----------------------------------------------------------
Hand              Simulated    Theoretical  Error

Straight Flush:   1.74e-05 1.39e-05 3.5e-06
Four of a Kind:   0.0002431 0.00024 3.10001e-06
Full House:       0.0014272 0.001441 1.38e-05
Flush:            0.0019919 0.001965 2.68999e-05
Straight:         0.0039166 0.003925 8.40006e-06
Three of a Kind:  0.0211624 0.021128 3.43993e-05
Two Pair:         0.04751 0.047539 2.89977e-05
Pair:             0.422784 0.422569 0.000214607
High Card:        0.500948 0.501177 0.000229239
-----------------------------------------------------------

Runtime: 5174 ms


These results demonstrate Monte Carlo convergence, where simulated probabilities approach theoretical values as the number of simulations increases.

## Monte Carlo Convergence

Simulations are performed with increasing sample sizes:

1000 -> 10000 -> 100000 -> 1000000 -> 10000000

As the number of simulations increases, the simulated probabilities approach the theoretical probabilities, demonstrating **Monte Carlo convergence** and the **Law of Large Numbers**.

## Project Structure

poker-probability-simulator
│
├── main.cpp
├── README.md
└── .gitignore

## Language

C++

## Author

Hitansh Aggarwal
