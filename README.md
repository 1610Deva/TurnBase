# TurnBase

TurnBase is a simple turn-based fighting game created as a college project. It allows players to simulate a battle between characters using a turn-based system.

## Features
- **Turn-based gameplay**: Players take turns attacking and defending.
- **Multiple characters**: Support for character selection and different stats.
- **Easy-to-use CLI interface**: Runs directly in the terminal.
- **Cross-platform support**: Compatible with Windows and Unix-based systems.

## How to Run

### Prerequisites
- **C++ compiler**: You can use `g++` (recommended) or `mingw`.

### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/Ariffansyah/TurnBase.git
   ```
2. Navigate to the project directory:
   ```bash
   cd TurnBase
   ```
3. Compile the program using `g++`:
   ```bash
   g++ -o game Main.cpp include/Base.cpp include/CLIDisplay.cpp include/Character.cpp include/Fight.cpp
   ```
4. Run the program:
   ```bash
   ./game
   ```

Alternatively, you can execute the provided batch or shell script:
- On Windows:
   ```bash
   TurnBase.bat
   ```
- On Unix-based systems:
   ```bash
   ./TurnBase.sh
   ```

### Note
If you want to view or use the older version of the game, it is available in the file `Turn_Base_Fighting.cpp`.

## Technologies Used
- **Language**: C++
- **Version Control**: Git

## Contributing
Contributions are welcome! To contribute:
1. Fork this repository.
2. Create a feature branch: 
   ```bash
   git checkout -b feature/YourFeatureName
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add a descriptive message"
   ```
4. Push to the branch:
   ```bash
   git push origin feature/YourFeatureName
   ```
5. Open a pull request on GitHub.

## License
This project does not currently have a license. Feel free to use it for educational purposes.

## Contact
For any questions or feedback, feel free to reach out:
- **GitHub**: [Ariffansyah](https://github.com/Ariffansyah)

Let me know if you'd like to add or adjust any sections!
