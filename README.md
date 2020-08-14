# Chessapeake

### How to run
Simply cd into the build directory respective of your OS (win-build, linux-build, mac-build) and run the executable.

### How to build
If you would like to build from source yourself, you can:  
1. mkdir build
2. cd build
3. cmake .. -G "Unix Makefiles"
4. make

### Notes
	- If running the Windows build, you may need to change the CLEAR_SHELL_COMMAND definition in src/main.cpp to "CLS" if you aren't using Cygwin unix commands.  


