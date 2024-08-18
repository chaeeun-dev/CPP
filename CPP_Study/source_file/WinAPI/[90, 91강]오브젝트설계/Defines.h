#pragma once
// 자주 쓰는 코드들을 매크로로 만들어 놓고 사용하기 

// 사용법은 DECLARE_SINGLE(classname);
#define DECLARE_SINGLE(classname)                      \
private:                                               \
    classname() {}                                     \
public:                                                \
    static classname* GetInstance()                    \
    {                                                  \
        static classname s_instance;                   \
        return &s_instance;                            \
    }

#define GET_SINGLE(classname)   classname::GetInstance()    // 싱글톤이라고 명시

#define SAFE_DELETE(ptr)    \
	if (_scene)             \
    {                       \
        delete _scene;      \
        _scene = nullptr;   \
    }
