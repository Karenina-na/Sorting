aux_source_directory(./algorithm ALGORITHM_SRC)
aux_source_directory(./distribution DISTRIBUTION_SRC)
aux_source_directory(./factory FACTORY_SRC)
aux_source_directory(./structure STRUCTURE_SRC)

# main
add_executable(${PROJECT_NAME} main.cpp)
target_sources(${PROJECT_NAME} PRIVATE ${ALGORITHM_SRC} ${STRUCTURE_SRC} ${DISTRIBUTION_SRC} ${FACTORY_SRC} )

target_include_directories(${PROJECT_NAME} PRIVATE ./structure)
target_include_directories(${PROJECT_NAME} PRIVATE ./algorithm)
target_include_directories(${PROJECT_NAME} PRIVATE ./factory)
target_include_directories(${PROJECT_NAME} PRIVATE ./distribution)