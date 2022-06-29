function (algos_test name)
  set(test_name ${name}_test)
  add_executable(${test_name}
    ${test_name}.cpp
  )
  target_link_libraries(${test_name}
    PRIVATE
    gtest_main
    fmt::fmt
    Eigen3::Eigen
    ${ARGN}
  )
  # target_include_directories(${test_name}
  #   PRIVATE
  #   "${CMAKE_CURRENT_LIST_DIR}/.."
  # )
  set_target_properties(${test_name}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/test"
  )
  gtest_discover_tests(${test_name})
endfunction()