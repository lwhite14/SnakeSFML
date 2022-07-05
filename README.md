# SnakeSFML
Recreation of the Snake game made with SFML and C++.

## Getting Started with Source
### Linux
If using a Linux OS, you can install SFML using a package manager and then run the Makefile. 
### Windows
Firstly, you will need to download the [Visual Studio Binaries](https://www.sfml-dev.org/download/sfml/2.5.1/).
The documentation advises you to build from source if you have a newer version of Visual Studio, 
however, I used the binaries for Visual Studio 2017 when using VS 2022. <br>
Extract the binaries to your preffered location, I moved the entire include and lib folders to a dependency
folder at the root of the project. Then, link to these folders in the 'Additional Include Directories' and 
'Additional Library Directories' options in the project settings. <br> 
Then, in 'Linker/Input', add 'sfml-graphics.lib', 'sfml-window.lib', 'sfml-system.lib', and 'sfml-audio.lib' to 
'Additional Dependencies' in the Release configuration, and add 'sfml-graphics-d.lib', 'sfml-window-d.lib', 
'sfml-system-d.lib', and 'sfml-audio-d.lib' in the Debug configuration. <br>
Finally, you will then need to add all the .dll files from the bin directory in your downloaded binaries
folder, to the root of the project. <br>
You can now debug the game! If you want to build the project, you will need to copy the .dll files that 
you handled whilst setting up the source code to where ever the built .exe file is. 
