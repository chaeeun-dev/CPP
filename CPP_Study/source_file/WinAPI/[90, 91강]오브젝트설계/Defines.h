#pragma once
// ���� ���� �ڵ���� ��ũ�η� ����� ���� ����ϱ� 

// ������ DECLARE_SINGLE(classname);
#define DECLARE_SINGLE(classname)                      \
private:                                               \
    classname() {}                                     \
public:                                                \
    static classname* GetInstance()                    \
    {                                                  \
        static classname s_instance;                   \
        return &s_instance;                            \
    }

#define GET_SINGLE(classname)   classname::GetInstance()    // �̱����̶�� ���

#define SAFE_DELETE(ptr)    \
	if (_scene)             \
    {                       \
        delete _scene;      \
        _scene = nullptr;   \
    }
