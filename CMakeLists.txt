cmake_minimum_required(VERSION 3.5)
project(G4HelloWorld)
set(CMAKE_CXX_STANDARD 14)


find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})

# copy macro file for visualization init
configure_file(${PROJECT_SOURCE_DIR}/init.mac
        ${PROJECT_BINARY_DIR}/init.mac
        COPYONLY
        )

set(SOURCE_FILES main.cpp HWDetectorConstruction.h HWActionInitialization.h HWPrimaryGeneratorAction.h HWDetectorConstruction.cpp HWSteppingAction.h HWEventAction.h HWRunAction.h)
add_executable(G4HelloWorld ${SOURCE_FILES})
target_link_libraries(G4HelloWorld ${Geant4_LIBRARIES})
