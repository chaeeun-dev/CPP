#pragma once

#include <windows.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <format>


// 메모리 릭 확인할 때 사용할 코드(파일과 라인이 출력)
#define _CRTDEBG_MAO_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)	
#endif
// 


#include "Types.h"
#include "Defines.h"
#include "Enums.h"

#include "Utils.h"

using namespace std;

