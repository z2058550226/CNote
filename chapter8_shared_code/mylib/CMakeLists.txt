#将当前CMakeList.txt所在文件夹中的所有文件用DIR_C8MYLIB来表示
aux_source_directory(. DIR_MYLIB)

#将当前目录下的文件都添加到静态库hfsecurity
add_library(hfsecurity STATIC ${DIR_MYLIB})

#指定静态链接库为标准C语言
set_target_properties(hfsecurity PROPERTIES LINKER_LANGUAGE C)