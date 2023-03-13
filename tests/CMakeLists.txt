include_directories(../src)

add_executable(test_geometry test_geometry.cpp  )
target_link_libraries(test_geometry libSTLTest)

add_executable(test_bodyfactory test_bodyfactory.cpp  )
target_link_libraries(test_bodyfactory libSTLTest)

add_executable(test_bodyboolean test_bodyboolean.cpp  )
target_link_libraries(test_bodyboolean libSTLTest)

add_executable(test_fileformat test_fileformat.cpp  )
target_link_libraries(test_fileformat libSTLTest)

add_executable(test_level_of_details test_level_of_details.cpp  )
target_link_libraries(test_level_of_details libSTLTest)

add_executable(test_meshoperations test_meshoperations.cpp  )
target_link_libraries(test_meshoperations libSTLTest)

add_executable(test_measurements test_measurements.cpp  )
target_link_libraries(test_measurements libSTLTest)

add_executable(test_Engine3D test_Renderer.cpp )
target_link_libraries(test_Engine3D libSTLTest)

add_executable(test_BMPFile test_BMPFile.cpp  )
target_link_libraries(test_BMPFile libSTLTest)