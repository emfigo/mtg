# MTG: Middle Temporal Gyrus

This project was named after a part of the brain in the temporal lobe. There has been studies that have suggested the MTG is involved in cognitive processes like language and memory processing. Which is one of the responsabilities of this project.

To reduce the scope I have created an interactive chat where the user can ask information to the MTG about the different groups of animals.

## Background

This project is inspired in Udacity Chatbot. From here I decided to simplify the entire project, add testing and also prepare it to use an API on top to run it from a web page. This requires a lot of infrastructure that is not necessary for this project (e.g frontend, docker and the API itself), so for simplification and to reduce dependencies this version of the project runs using the wxWidget UI locally.

### What to expect

- This repo contains a sample conversation about animals, so the answers are limited, but the aim was to make the bot as natural as possible. Of course you can feel free to add a different answer graph and the bot will interact with you the same way as long as it meets the criteria of the file.

- Also the aim of this project was to completely separate the UI from the backend, so the bot could be used with different UIs without affecting the main logic.


### What is not

- There are missing bits that I would add in a real project like (logging [not cout :)], monitoring etc), but again this is meant to be a sample project that you can understand and make it work really quick.
- Even though this is prepared to have multiple bots running in parallel, because of using the UI I'm using, multithread was not introduced in this project.

## Assumptions

- Even though instructions for all environments are present. This project was developed using iOS Catalina and only tested in an iOS Catalina and LUbuntu environment.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* wxWidgets >= 3.0
  * Linux: `sudo apt-get install libwxgtk3.0-dev libwxgtk3.0-0v5-dbg`
  * Mac: There is a [homebrew installation available](https://formulae.brew.sh/formula/wxmac).
  * Installation instructions can be found [here](https://wiki.wxwidgets.org/Install). Some version numbers may need to be changed in instructions to install v3.0 or greater.


## Basic Build Instructions

1. Clone this repo with the submodules `git clone --recursive https://github.com/emfigo/mtg.git`.
2. cd into project `cd mtg`
3. Make a build directory in the top level directory: `mkdir build && cd build`
4. Compile: `cmake .. && make`

### Running tests

First to make sure that everything is working as expected run the tests. For this just triiger:

For unit tests:
```bash
./tests/unit
```

For integration tests:
```bash
./tests/integration
```

## Running the ChatBot locally
1. Go to the build directory `cd build` if you are not already there.
2. Run it: `./mtg`.
