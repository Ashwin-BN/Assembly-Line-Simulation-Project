# Assembly Line Simulation Project

Welcome to the Assembly Line Simulation Project! This project is a final assignment for OOP345 course at Seneca College. The purpose of this project is to develop a simulation of an assembly line with any number of stations. This README will guide you through the project structure and the different modules implemented.

## Table of Contents

- [Overview](#overview)
- [Project Structure](#project-structure)
- [Modules](#modules)
- [Instructions](#instructions)
- [Credits](#credits)

## Overview

The project aims to simulate an assembly line with multiple workstations. Each station holds a set of specific stock items and is responsible for processing customer orders by filling the orders with the items requested. Orders are processed along the line until they are either completed or left incomplete due to a lack of inventory.

## Project Structure

The project is divided into three milestones:

- **Milestone 1 (MS1):** Implementation and testing of the Utilities and Station modules.
- **Milestone 2 (MS2):** Implementation and testing of the CustomerOrder module.
- **Milestone 3 (MS3):** Implementation and testing of the Workstation and LineManager modules.

## Modules

### Utilities Module

- Manages string parsing and token extraction.
- Handles field width and delimiters.

### Station Module

- Represents a workstation on the assembly line.
- Handles stock items and processes customer orders.

### CustomerOrder Module

- Represents a customer order.
- Handles the items requested by the customer and their completion status.

### Workstation Module

- Manages a specific item on the assembly line.
- Processes orders and attempts to move them down the line.

### LineManager Module

- Configures the assembly line and manages customer orders as they move through the stations.
- Tracks iterations and handles completed and incomplete orders.

## Instructions

To set up the project, ensure you have the necessary files as outlined in the milestones above. Compile and run the project using the command line and follow the output for instructions.

This project is designed to help you practice and apply your C++ Object-Oriented Programming skills.

## Credits

This project was created as part of the OOP345 course at Seneca College. 
The `reflect.txt` file is included in the repository and reflecting on the project journey and learning experiences.

- **Author**: Ashwin B N
- **Institution**: Seneca College
- **Course**: IPC144




---
