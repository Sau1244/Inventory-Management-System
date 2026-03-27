# Inventory-Management-System

## Description

This project implements a simple inventory
management system. The system demonstrates 
object-oriented design, modern C++ features,
generic programming, STL algorithms, smart pointers,
and robust error handling.

The system manages items such as Electronics and Grocery,
and provides functionality for an inventory with some
simple validation.

The project includes a CLI and an example application
demonstrating the functionality.

## Features

- Object-oriented design
- Smart pointers
- STL containers and algorithms
- Template functions
- Custom exception hierarchy
- CSV file import/export
- Command-line interface (CLI)

## Command-Line Interface (CLI)

The CLI allows you to:
- Add Electronics or Grocery item
- Remove Item by ID
- Update Quantity by ID
- Display Inventory
- Read From/Write to File
- Find the most expensive Items
- Finds items below a specified quantity threshold
- Sort inventory by price (ascending/descending)

## Build Instructions

```bash
mkdir build
cd build
cmake ..
make
```

Run example (in directory "build"):

```bash
./cli/cli_app
```
or
```bash
./example/example_demo
```

## Questionnaire

### 1. Which of these areas excites you most? (rank or select top 5)
- Application security/vulnerability research/cybersecurity
- AI/ML model development & LLM integration
- Developer tooling & automation
- Code analysis (static/dynamic)
- DevSecOps & CI/CD pipelines
- Mobile app development
- Game development & graphics
- Frontend/UI design & user experience
- Data visualization & user experience
- Data visualization & dashboards
- Database administration
- Cloud services
- Backend development

#### My answer:
- Backend development
- Developer tooling & automation
- Code analysis (static/dynamic)
- Application security
- Database administration

### 2. Where do you prefer to work in a software stack?
#### My Answer: 
- Mostly Backend.

### 3. Which type of engineering work appeals to you more?
- Building user-facing products & features
- Building infrastructure
- CI/CD pipelines & build systems
- Equal interest in both

#### My answer:
- Building user-facing products & features (functional/backend focus)
- Building infrastructure

### 4. What frustrates you most about security tooling today? (2-3 sentences)

#### My answer:
I am not an expert in this field, but to my knowledge, many security tools
generate a large number of alerts, which has many false positives, and that can
really waste time or it is easy to miss a real alert.

### 5. If you had a week to build anything combining AI + security, what would you build?

#### My answer:
If I had a week to build something combining AI + security, I would try to build 
a system that could detect potential scams in messages and send me a warning.
The system could detect suspicious patterns or unusual behaviour, and analyze message content.
For example, always send a warning if someone asks for money and creates a lot of pressure.

### 6. Which deployment and runtime environment interests you most?

#### My answer:
- Desktop/CLI applications

### 7. How comfortable are you reading security advisories, CVEs, or vulnerability disclosures?

#### My answer:
- Willing to learn

### 8. What's your reaction when an AI tool produces a false positive? (2-3 sentences)

#### My answer:
When an AI tool produces a false positive, I try to understand, why it produced that result.
I think that false positives are a normal part of the system, so I would try to verify them and
filter properly to avoid hiding real alerts.

## Notes

The project was implemented with focus on clean object-oriented design. 
Some parts, like exception, certain algorithms, or ways of organizing code
were new to me, but really valuable.

I felt a lot of satisfaction doing this project, especially, because 
it has some large structure, that had a lot of functionalities.

The hardest part, was implementing the CLI. It took me time to
think about the hierarchy and decide what functionality to add.

I see some details that I could improve in the future,
but to me, the app I made, is usable and easy to change and maintain.