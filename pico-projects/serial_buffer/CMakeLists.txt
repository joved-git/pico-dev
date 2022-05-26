cmake_minimum_required(VERSION 3.21)

include(pico_sdk_import.cmake)

project(serial_buffer)

pico_sdk_init()

add_executable(serial_buffer
serial_buffer.c
)

target_link_libraries(serial_buffer pico_stdlib)

pico_enable_stdio_usb(serial_buffer 1)
pico_enable_stdio_uart(serial_buffer 0)

pico_add_extra_outputs(serial_buffer)