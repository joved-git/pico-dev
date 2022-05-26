cmake_minimum_required(VERSION 3.21)

include(pico_sdk_import.cmake)

project(i2c_test C CXX ASM)

pico_sdk_init()

add_executable(i2c_test
    i2c_test.c
)

target_link_libraries(i2c_test 
    pico_stdlib
    hardware_i2c
)

pico_enable_stdio_usb(i2c_test 1)
pico_enable_stdio_uart(i2c_test 0)

pico_add_extra_outputs(i2c_test)