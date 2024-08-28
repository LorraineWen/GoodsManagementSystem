aux_source_directory(. CONTROLLOERLIB)
add_library(controllerlib ${CONTROLLOERLIB})
target_link_libraries(controllerlib modellib toollib mysqlcppconn)