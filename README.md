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
number_of_philosophers: The number of philosophers and forks.
time_to_die (in milliseconds): Time after which a philosopher dies if they haven't started eating.
time_to_eat (in milliseconds): Time it takes for a philosopher to eat.
time_to_sleep (in milliseconds): Time a philosopher spends sleeping.
number_of_times_each_philosopher_must_eat (optional): Simulation stops if each philosopher has eaten at least this number of times. If not specified, the simulation stops when a philosopher dies.
Example

sh

./philo 5 800 200 200

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

To-Do List

    Set up Project Structure

 Create philo/ directory.

     Create Makefile, philo.h, main.c, philosopher.c, utils.c.

Write Makefile

 Define compilation rules and flags.

     Add rules for all, clean, fclean, re.

Define Structures in philo.h

 Define philosopher and shared data structures.

     Declare function prototypes.

Implement Utility Functions in utils.c

 Implement current_time() to get current timestamp.

     Implement usleep_ms() to sleep for specified milliseconds.

Implement Philosopher Routine in philosopher.c

 Implement print_status() to print philosopher status.
 Implement eat() to handle eating routine.

     Implement philosopher_routine() to define philosopher behavior.

Initialize and Run Simulation in main.c

 Implement init_data() to initialize simulation data.
 Implement cleanup() to free resources and destroy mutexes.

         Implement main() to start the simulation and manage threads.

License

This project is licensed under the MIT License - see the LICENSE file for details.

markdown


### Explanation of Each Section

1. **Overview**: Provides a brief summary of the project and its goals.
2. **Requirements**: Lists the necessary tools to build and run the project.
3. **Installation**: Step-by-step instructions to clone the repository and build the project.
4. **Usage**: Explains how to run the program with command-line arguments and provides an example.
5. **Project Structure**: Describes the files in the project and their roles.
6. **How It Works**: Detailed explanation of the program's functionality, including initialization, the philosopher routine, synchronization, and termination.
7. **To-Do List**: A checklist of tasks to implement the project.
8. **License**: Specifies the licensing information.

ChatGPT can make mistakes. Check
