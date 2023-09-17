aux_source_directory(./algorithm ALGORITHM_SRC)
aux_source_directory(./analysis ANALYSIS_SRC)
aux_source_directory(./factory FACTORY_SRC)

# main
add_executable(${PROJECT_NAME} main.cpp ${ALGORITHM_SRC} ${ANALYSIS_SRC} ${FACTORY_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ./algorithm)
target_include_directories(${PROJECT_NAME} PRIVATE ./analysis)
target_include_directories(${PROJECT_NAME} PRIVATE ./factory)
