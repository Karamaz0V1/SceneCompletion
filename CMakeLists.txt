PROJECT(sceneCompletion)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

find_package(OpenCV REQUIRED)


add_compile_options("$<$<CONFIG:DEBUG>:-Wall>")

SET(SRC 
    main.cpp
    grabcut.cpp
    MinSeam.cpp
    utils.cpp
    )

SET(HDR
    grabcut.h
    MinSeam.h
    utils.h
    )

ADD_EXECUTABLE(${PROJECT_NAME} ${SRC} ${HDR})
ADD_EXECUTABLE(grabcut_demo grabcut_demo.cpp grabcut.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(grabcut_demo ${OpenCV_LIBS})
