# ProjectModuleSystem
## Implementation of the Module System from Smoothieware.


### Overview

Implementation of the Module System that is part of the application design of
Smoothieware (https://github.com/VandalForge/Smoothieware), the operating system
designed for use in CNC machines written in C++ by The Smoothie Project. The 
system uses a module interface to enable developers to add custom modules for 
increased functionality. Modules register for events with the Kernel and have
functions called on events.

### Architecture

```mermaid
classDiagram
```

### Directory Structure

```
```

---

### Design

[//]: # (TODO: Flesh out design paragrpahs for project.)


## Build

This project uses CMake to generate the build files.

### 1. Clone the repository to your desired project directory.

```bash
# from the desired parent directory

git clone https://github.com/BocanOnline/ProjectModuleSystem

```

### 3. Build the project.

This project includes helper scripts to build, run, test, and clean the project. 
These scripts can all be ran from the project root. These scripts require CMake 
to be installed as well as your build system of choice (e.g. Make, Ninja, etc.).

```bash
# setup the scripts as executables, you only need to do this once

chmod +x ./scripts/build-clean.sh \
./scripts/build-debug.sh \
./scripts/build-release.sh \
./scripts/build-test.sh \
./scripts/build-run-debug.sh \
./scripts/build-run-release.sh
```

```bash
# run each script from the project directory

./scripts/clean.sh              # clean all artifacts and delete build directories 
./scripts/build-debug.sh        # build the debug configuration to build-debug/ 
./scripts/build-release.sh      # build the release configuration to build-release/
./scripts/run-test.sh           # run all registered tests with ctest 
./scripts/run-debug.sh          # run the debug binary 
./scripts/run-release.sh        # run the release binary
```

[//]: # (### 4. Developing.)
[//]: # (## Adding Modules to the Library.)
[//]: # (## Adding Third-Party Libraries.)
[//]: # (## Adding Application-Specific Code.)
[//]: # (### 5. Testing.)
[//]: # (## Registering New Tests.)
[//]: # (### 6. Building.)
[//]: # (## Adding New Binaries -Libraries or Executables-.)
[//]: # (## Adding New Build Configurations.)

---

## Documentation

README.md

[//]: # ([CONTRIBUTING.md](/CONTRIBUTING.md))

[//]: # (TODO: Add link to docs/ root to documentation tree.)


### License

This project is published under The Unlicense. 
The code is public domain; use it however you want. 

Full text in [LICENSE.md](/LICENSE.md)
