# Chessapeake
## A simple terminal-based chess program.

### How to build + run
First make sure you have CMake and a C++ compiler installed.

With GNU Make:
\>> mkdir build  
\>> cd build  
\>> cmake .. -G "Unix Makefiles"  
\>> make

With Ninja:
\>> mkdir build  
\>> cd build  
\>> cmake .. -G "Ninja"  
\>> ninja

Once the build is complete, run the executable titled 'out'.

### How to Play
Simply type the algebraic chess notation for the move you would like to make and press Enter to submit it.  
Special commands:  
>> 'u' : undo the last move  
>> 'r' : redo the last undid move  
>> 'exit' : end the game

Made for local 2-player play.

### Notes
- If running the Windows build, you may need to change the CLEAR_SHELL_COMMAND definition in src/main.cpp to "CLS" if you aren't using Cygwin unix commands.  

