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

add_executable(test_fractal_tetrahedron test_fractal_tetrahedron.cpp  )
target_link_libraries(test_fractal_tetrahedron libSTLTest)

add_executable(test_measurements test_measurements.cpp  )
target_link_libraries(test_measurements libSTLTest)

add_executable(test_renderer test_renderer.cpp )
target_link_libraries(test_renderer libSTLTest)

add_executable(test_bmpfile test_bmpfile.cpp  )
target_link_libraries(test_bmpfile libSTLTest)

add_executable(test_stepfile test_stepfile.cpp  )
target_link_libraries(test_stepfile libSTLTest)