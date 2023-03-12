add_executable(picow_connection
        connection.c
        )

pico_enable_stdio_usb(picow_connection 1)
pico_enable_stdio_uart(picow_connection 0)

target_include_directories(picow_connection PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        )
# create map/bin/hex file etc.
pico_add_extra_outputs(picow_connection)
target_link_libraries(picow_connection
        pico_cyw43_arch_lwip_threadsafe_background 
        pico_stdlib
        )