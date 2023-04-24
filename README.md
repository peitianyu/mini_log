## 使用时注意根据自己需要修改文件大小, 最大文件数量与文件保存path

```c++
#define LOG_FILE_PATH "log/" 	// 修改日志文件存放路径
#define MAX_LOG_CACHE_SIZE 1024 // 修改缓存日志大小
#define MAX_LOG_FILE_SIZE 2048  // 修改单文件最大大小
#define MAX_LOG_FILE_NUM 10     // 修改最大文件数

// 配置输出到文件还是终端
#define LOG_TO_FILE
```

## 测试方法

```shell
mkdir build
cd build && mkdir log
cmake ..
make -j
./main
```
