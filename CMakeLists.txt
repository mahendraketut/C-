cmake_minimum_required(VERSION 3.21)
project(newCovidTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(newCovidTest main.cpp CTIS.cpp User.cpp Patient.cpp CentreOfficer.cpp TestCentre.cpp TestKit.cpp CovidTest.cpp CTIS.h)
