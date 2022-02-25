# Chessapeake
## A simple terminal-based chess program.

### How to run
Simply 'cd' into the build directory respective of your OS (win-build, linux-build, mac-build) and run the executable.

### How to build
If you would like to build from source yourself, you can:  
\>> mkdir build  
\>> cd build  
\>> cmake .. -G "Unix Makefiles"  
\>> make  

### How to Play
Simply type the algebraic chess notation for the move you would like to make and press Enter to submit it.  
Special commands:  
>> 'u' : undo the last move  
>> 'r' : redo the last undid move  
>> 'exit' : end the game

Made for local 2-player play.

### Notes
- If running the Windows build, you may need to change the CLEAR_SHELL_COMMAND definition in src/main.cpp to "CLS" if you aren't using Cygwin unix commands.  
