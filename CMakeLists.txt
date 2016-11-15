include_directories(src/include)

add_subdirectory(src/exec)
add_subdirectory(src/parser)
add_subdirectory(src/lexer)

set(SRC
    src/42sh.c
    #$<TARGET_OBJECTS:parser_obj>
    #$<TARGET_OBJECTS:exec_obj>
    $<TARGET_OBJECTS:lexer_obj>)

add_executable(42sh ${SRC})
