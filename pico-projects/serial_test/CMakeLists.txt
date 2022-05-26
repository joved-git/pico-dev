cmake_minimum_required(VERSION 3.21)

include(pico_sdk_import.cmake)

project(serial_test C CXX ASM)

pico_sdk_init()

add_executable(serial_test
serial_test.c
)

target_link_libraries(serial_test pico_stdlib)

pico_enable_stdio_usb(serial_test 1)
pico_enable_stdio_uart(serial_test 0)

pico_add_extra_outputs(serial_test)