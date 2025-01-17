#include "Literature.h"
#define Dao Singleton<Literature>::GetInstance()

template <typename T>
class Singleton{
public:
	template<typename...Args>
	static T * Instance(Args &&...args){
		if (m_pInstance == nullptr)
			m_pInstance = new T(std::forward<Args>(args)...);//完美转发
		return m_pInstance;

	}
	//获取单例
	static T * GetInstance(){
		if (m_pInstance == nullptr)
			throw std::logic_error("the instance is not init,please initialize the instance first");
		return m_pInstance;
	}
	static void DestoryInstance(){
		delete m_pInstance;
		m_pInstance = nullptr;
	}
private:
	Singleton(void);
	virtual ~Singleton(void);
	Singleton(const Singleton&);
	Singleton & operator =(const Singleton &);
private:
	static T *m_pInstance;
};
template <class T> T * Singleton<T>::m_pInstance = nullptr;