#include <vector>

class abstract_file {
    public:
    virtual ~abstract_file() = default;

    // Pure virtual functions
    virtual void read() = 0;
    virtual int write(const std::vector<char>& data) = 0;
    virtual int append(std::vector<char>& data) = 0;
    virtual unsigned int getSize() const = 0;
    virtual std::string getName() const = 0;
};