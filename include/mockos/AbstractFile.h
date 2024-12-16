

#ifndef ABSTRACT_FILE_H
#define ABSTRACT_FILE_H

class AbstractFileVisitor;

#include <vector>
class AbstractFile {
    public:
    virtual ~AbstractFile() = default;

    // Pure virtual functions
    virtual std::vector<char> read() = 0;
    virtual int write(const std::vector<char>& data) = 0;
    virtual int append(std::vector<char>& data) = 0;
    virtual unsigned int getSize() const = 0;
    virtual std::string getName() const = 0;
    virtual void accept(AbstractFileVisitor* file) = 0;
    virtual AbstractFile* clone(std::string copy) = 0;
};

#endif

