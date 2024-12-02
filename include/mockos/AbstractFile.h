#include <vector>
#ifndef ABSTRACT_FILE_H
#define ABSTRACT_FILE_H
class AbstractFile {
    public:
    virtual ~AbstractFile() = default;

    // Pure virtual functions
    virtual void read() = 0;
    virtual int write(const std::vector<char>& data) = 0;
    virtual int append(std::vector<char>& data) = 0;
    virtual unsigned int getSize() const = 0;
    virtual std::string getName() const = 0;
};

#endif
