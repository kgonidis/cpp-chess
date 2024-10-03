# ChessEngine Library

# Table of Contents
- [ChessEngine Library](#chessengine-library)
- [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Features](#features)
  - [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Building the Library](#building-the-library)
    - [iOS Build](#ios-build)
  - [Project Structure](#project-structure)
  - [Documentation](#documentation)
    - [Header Files](#header-files)
    - [Source Files](#source-files)
  - [Contributing](#contributing)
  - [License](#license)
  - [Acknowledgements](#acknowledgements)

## Overview

The ChessEngine library is a comprehensive chess engine designed to facilitate the development of chess applications. It provides a robust set of features for handling chess game logic, move generation, and game state management. The library is written in C++ and includes support for both C and C++ interfaces.

## Features

- **Game State Management**: Manage the state of a chess game, including piece positions, castling rights, en passant squares, and more.
- **Move Generation**: Generate legal moves for all pieces, including special moves like castling and en passant.
- **PGN Parsing**: Parse and generate Portable Game Notation (PGN) for recording and replaying chess games.
- **Bitboard Representation**: Efficiently represent the chessboard and pieces using bitboards.
- **Zobrist Hashing**: Use Zobrist hashing for fast game state comparison and transposition table implementation.
- **Attack Patterns**: Precompute and store attack patterns for all pieces to speed up move generation.

## Getting Started

### Prerequisites

- C++ compiler
- CMake
- Git

### Building the Library

1. Clone the repository:
   ```sh
   git clone --recurse-submodules https://github.com/kgonidis/cpp-chess.git 
   ```

2. Create a build directory and navigate to it:
   ```sh
   mkdir build && cd build
   ```

3. Run CMake to configure the project:
   ```sh
   cmake ..
   ```

4. Build the project:
   ```sh
   cmake --build .
   ```

### iOS Build

To build the project for iOS, use the `build_ios.sh` script:

```sh
./build_ios.sh
```

## Project Structure

- `src/`: Contains the source code for the chess engine.
- `include/`: Contains the header files for the chess engine.
- `assets/`: Contains assets such as images and PGN files.
- `tests/`: Contains test files for the chess engine.
- [`vendor/`]: Contains third-party libraries used by the project.

## Documentation

### Header Files

- `engine.h`: Main header file that includes all other headers.
- `constants.h`: Defines various constants used throughout the project.
- `attacks.h`: Functions for computing attack patterns for different pieces.
- `movetree.h`: Defines the move tree structure for storing game moves.
- `game.h`: Defines the game structure and functions for manipulating game states.
- `types.h`: Defines various types and enums used in the project.
- `gametree.h`: Functions for parsing and generating PGN files.

### Source Files

- `chessengine_test.c`: C test file for the chess engine.
- `chessengine_test.cpp`: C++ test file for the chess engine.
- `ui_test.cpp`: C++ file for testing the graphical user interface.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes.

## License

This project is licensed under the MIT License. See the [`LICENSE`] file for details.

## Acknowledgements

- [ImGui](https://github.com/ocornut/imgui)
- [GLM](https://github.com/g-truc/glm)
- [ANTLR4](https://github.com/antlr/antlr4)
- [iOS-CMake](https://github.com/leetal/ios-cmake)

