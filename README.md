# Dining Philosophers Simulation

This project is a simulation of the classic "Dining Philosophers" problem using threads and mutexes in C. The goal is to manage concurrent philosophers who alternate between eating, thinking, and sleeping while avoiding starvation and ensuring proper synchronization.

## Table of Contents

- [Overview](#overview)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [How It Works](#how-it-works)
- [To-Do List](#to-do-list)
- [License](#license)

## Overview

In this project, several philosophers sit at a round table with a bowl of spaghetti in the middle. Each philosopher needs two forks to eat. There are as many forks as philosophers. The simulation ensures that no philosopher starves and that all philosophers properly alternate between eating, thinking, and sleeping.

## Requirements

- GCC (GNU Compiler Collection)
- Make (build automation tool)

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/dining-philosophers.git
    cd dining-philosophers/philo
    ```

2. Build the project:
    ```sh
    make
    ```

## Usage

To run the simulation, use the following command:

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
number_of_philosophers: The number of philosophers and forks.
time_to_die (in milliseconds): Time after which a philosopher dies if they haven't started eating.
time_to_eat (in milliseconds): Time it takes for a philosopher to eat.
time_to_sleep (in milliseconds): Time a philosopher spends sleeping.
number_of_times_each_philosopher_must_eat (optional): Simulation stops if each philosopher has eaten at least this number of times. If not specified, the simulation stops when a philosopher dies.
Example

```sh

./philo 5 800 200 200
```
This command starts a simulation with 5 philosophers, where each philosopher dies after 800ms without eating, takes 200ms to eat, and sleeps for 200ms.
Project Structure

css

philo/
├── Makefile
├── philo.h
├── main.c
├── philosopher.c
├── utils.c

    Makefile: Build instructions.
    philo.h: Header file with structures and function prototypes.
    main.c: Initialization and main program loop.
    philosopher.c: Philosopher routines and behaviors.
    utils.c: Utility functions for time management.

How It Works

    Initialization:
        Parse command-line arguments.
        Initialize data structures and mutexes.
        Create philosopher threads.

    Philosopher Routine:
        Philosophers alternately think, eat, and sleep.
        Mutexes ensure that forks are used by only one philosopher at a time.
        Each philosopher logs their actions with timestamps.

    Synchronization:
        Mutexes are used to prevent race conditions.
        Each fork is protected by a mutex.
        A print mutex ensures that log messages do not overlap.

    Termination:
        The simulation stops when a philosopher dies or when all philosophers have eaten the required number of times (if specified).
