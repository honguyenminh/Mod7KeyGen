# mod7KeyGen
A basic product key generator for Microsoft products from 90s that use mod7 algorithm (e.g Windows 95, Office 97, Windows NT,...)
This repo isn't meant to encourage piracy, only used for sciectific or educational purposes.
The code and algorithm written here is not clean and efficient at all, but hey.

Algorithm source: [gurney.dev/posts/mod7/](https://gurney.dev/posts/mod7/)

## About
mod7KeyGen is a terminal (console) app, yes the black box with weird text that you have to type text in to use your computer.

Releases are compiled with CMake, everything should work with any CMake compatible IDE (Visual Studio, CLion,...)

## Instructions
To run this app, don't double-click it, won't work.
Instead, you have to run from a console emulator (Command Prompt on Windows).

### How to run
1. Download the latest release, then extract (if needed) to your desired folder (Desktop should work I guess)
2. Open command prompt and navigate to that folder with cd command, or,
   Hold down Shift and right-click the folder, then "Open command window here"
3. Type command with syntax described below, or just type `MOD7KeyGen.exe --help`

### Syntax
Command syntax:    MOD7KeyGen.exe    {argument}(required)   {number of key(s)}(optional)

{argument} is required to set key type, list below.  
Generate 1 key with the specified key type set by {argument}  
Number of key(s) generated can be modified with the {number of key} option  
**Warning: Only one argument can be passed at a time.**

### Arguments list
Shorthand args | Full-size args | Description
-------------- | -------------- | -----------
-h | --help | Display help screen
-10 | --10digitCD | Set key type as 10-digit for CD retails. Is oftenly used in Windows 95, NT,... as CD retails
-11 | --11digitCD | Set key type as 11-digit for CD retails. This type can be found in Office 97,...
-20 | --20digitOEM | Set key type as 20-digit for OEM versions.

Example command:  MOD7KeyGen.exe -11      
MOD7KeyGen.exe -20 5

## Build instruction (not tested on other machine)
### Dependencies
Any IDE with CMake
### Build manually
Clone repo or download as zip, then extract to a folder
#### With IDE
1. Open CMake file in your favorite IDE
2. Build it
#### With console
1. Install CMake if you haven't, make sure you can run it from your console.  
**CMake install directory should be in your PATH.**
2. Make a directory inside cloned repo, name it whatever you want. This folder will store your built binary (executable).
3. Open a console in that folder.
4. Do a `cmake ../<BuildFolder>` replacing `<BuildFolder>` with the build folder that you created earlier. You might need to replace forward-slash `/` with back-slash `\ ` on Windows.
5. Build with `cmake --build .` mind the space between `--build` and `.`

This thing has SUPER COW POWER.