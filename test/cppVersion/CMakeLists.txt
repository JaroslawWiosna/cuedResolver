project(cppVersion)

file(GLOB src
  "*.cpp"
  ../../Cell/Cell.hpp
)

add_executable(${PROJECT_NAME} ${src} )

target_link_libraries(
  ${PROJECT_NAME} 
  ${LINK_FLAGS}
)


add_test(${PROJECT_NAME} ${PROJECT_NAME})
