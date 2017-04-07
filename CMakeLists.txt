cmake_minimum_required(VERSION 3.5)
project(G4HelloWorld)
set(CMAKE_CXX_STANDARD 14)


find_package(Geant4 REQUIRED)
include(${Geant4_USE_FILE})


set(SOURCE_FILES main.cpp HWDetectorConstruction.h HWActionInitialization.h HWPrimaryGeneratorAction.h HWDetectorConstruction.cpp HWSteppingAction.h HWEventAction.h HWRunAction.h)
add_executable(G4HelloWorld ${SOURCE_FILES})
target_link_libraries(G4HelloWorld ${Geant4_LIBRARIES})
