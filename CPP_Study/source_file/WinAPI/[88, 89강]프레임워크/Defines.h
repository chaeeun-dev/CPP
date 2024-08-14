#pragma once

// 매크로 코드, 사용법은 DECLARE_SINGLE(classname);
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