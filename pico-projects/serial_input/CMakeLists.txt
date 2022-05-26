cmake_minimum_required(VERSION 3.21)

include(pico_sdk_import.cmake)

project(serial_input)

pico_sdk_init()

add_executable(serial_input
serial_input.c
)

target_link_libraries(serial_input pico_stdlib)

pico_enable_stdio_usb(serial_input 1)
pico_enable_stdio_uart(serial_input 0)

pico_add_extra_outputs(serial_input)