# CMakeList.txt: projeto de CMake para Graphing, incluir origem e definir
# lógica específica a um projeto aqui.
#
cmake_minimum_required (VERSION 3.8)

# Habilite a Recarga Dinâmica para compiladores MSVC, se houver suporte.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Graphing")

# Adicina o SFML a partir do seu repositório
include(FetchContent)
FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG        2.6.x
)
FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

link_directories("${CMAKE_BINARY_DIR}/lib/sfml")

set(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

# Adicione a origem ao executável deste projeto.
file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)
add_executable (Graphing ${SOURCES})

target_link_libraries(Graphing
    PRIVATE
        sfml-audio
        sfml-graphics
        sfml-system
        sfml-window
        nlohmann_json::nlohmann_json
)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Graphing POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Graphing> $<TARGET_FILE_DIR:Graphing> COMMAND_EXPAND_LISTS)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Graphing PROPERTY CXX_STANDARD 20)
endif()
