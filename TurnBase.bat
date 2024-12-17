@echo off
rem Compile the C++ program
g++ Main.cpp include/Base.cpp include/CLIDisplay.cpp include/Character.cpp include/FightSystem.cpp -o TurnBase.exe

rem Run the compiled program
TurnBase.exe

pause
