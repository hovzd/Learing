#include <iostream>

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		static Singleton singleton;//此变量存在静态区，C++11自带两段检查锁机制来确保static变量实例化一次
		return &singleton;
	}
	
private:
	Singleton(){}
    ~Singleton(){}
};
 
int main()
{
	auto p1 = Singleton::GetInstance();
	auto p2 = Singleton::GetInstance();
	bool result = (p1 == p2);
	std::cout << "result:" <<result << std::endl;
 
	return 0;
}