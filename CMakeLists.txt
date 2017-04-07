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

set(SOURCE_FILES main.cpp include/HWDetectorConstruction.h include/HWActionInitialization.h include/HWPrimaryGeneratorAction.h src/HWDetectorConstruction.cpp include/HWSteppingAction.h include/HWEventAction.h include/HWRunAction.h src/HWActionInitialization.cpp src/HWEventAction.cpp src/HWPrimaryGeneratorAction.cpp src/HWRunAction.cpp src/HWSteppingAction.cpp)
add_executable(G4HelloWorld ${SOURCE_FILES})
target_link_libraries(G4HelloWorld ${Geant4_LIBRARIES})
