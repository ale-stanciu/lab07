cmake_minimum_required(VERSION 3.21)
project(lab07)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab07 main.cpp Domain/Entity.cpp Domain/Entity.h Repo/Repo.cpp Repo/Repo.h Tests/Tests.cpp Tests/Tests.h UI/console.cpp UI/console.h Service/Service.cpp Service/Service.h)
