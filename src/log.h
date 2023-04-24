#ifndef __COMMON_LOG_H__
#define __COMMON_LOG_H__

#define LOG_FILE
#ifdef LOG_FILE
#include<fstream>
#include<sstream>
#include<sys/stat.h>
#include<mutex>

#define LOG_FILE_PATH "log/"

class LogFile
{
public:
    LogFile()
    {
        m_file_name = LOG_FILE_PATH + std::string(__DATE__) + "_" + std::to_string(m_file_num++) + ".log";
        m_file.open(m_file_name, std::ios::out | std::ios::app);
    }

    ~LogFile() { m_file.close(); }

    void WriteLog(const std::string &log){
        m_file << log;
        m_file.flush();
    }

    std::string GetFileName() { return m_file_name; }
private:
    static uint m_file_num;
    std::string m_file_name;
    std::ofstream m_file;
};

uint LogFile::m_file_num = 0;


#define MAX_LOG_FILE_SIZE 1024
#define MAX_LOG_FILE_NUM 10


class LogFileManage
{
public:
    static LogFileManage *GetInstance()
    {
        static LogFileManage instance;
        return &instance;
    }

    template <typename T>
    void WriteLog(const T &arg)
    {
        m_mutex.lock();
        ManageFile();

        m_log_file->WriteLog(arg);
        m_mutex.unlock();
    }

    template <typename T, typename... Types>
    void WriteLog(const T &firstArg, const Types &...args)
    {
        m_mutex.lock();
        ManageFile();

        m_log_file->WriteLog(firstArg);
        WriteLog(args...);
        m_mutex.unlock();
    }

private:
    void ManageFile()
    {
        if (m_log_file == nullptr){
            m_log_file = new LogFile();
        }

        struct stat statbuf;
        stat(m_log_file->GetFileName().c_str(), &statbuf);

        std::cout << "file size: " << statbuf.st_size << std::endl;

        if (statbuf.st_size > MAX_LOG_FILE_SIZE){
            delete m_log_file;
            m_log_file = new LogFile();

            RemoveFile();
        }
    }

    void RemoveFile()
    {
        // 删除超出最大文件数的文件
        std::string cmd = "ls " + std::string(LOG_FILE_PATH) + " -t | awk '{if(NR>10) print $0}'";
        FILE *fp = popen(cmd.c_str(), "r");
        if (fp == nullptr) return;

        char buf[1024];
        while (fgets(buf, sizeof(buf), fp) != nullptr){
            std::string file_name = std::string(LOG_FILE_PATH) + buf;
            file_name.erase(file_name.end() - 1);
            remove(file_name.c_str());
        }
    }


    LogFileManage() : m_log_file(nullptr) {}
    ~LogFileManage()
    {
        if (m_log_file != nullptr){
            delete m_log_file;
            m_log_file = nullptr;
        }
    }

private:
    LogFile *m_log_file;
    std::mutex m_mutex;
};

#define LOG_FILE_DEBUG(...) LogFileManage::GetInstance()->WriteLog("[", __TIME__, "] ", __VA_ARGS__)


#endif // LOG_FILE


#endif // __COMMON_LOG_H__