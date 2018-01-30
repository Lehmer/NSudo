// NSudoC.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "resource.h"

#include <Windows.h>

#include "m2base.h"

std::wstring NSudoGetUTF8StringResources(
	_In_ UINT uID)
{
	HMODULE Module = GetModuleHandleW(nullptr);

	HRSRC Resource = FindResourceExW(
		Module,
		L"String",
		MAKEINTRESOURCEW(uID),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL));

	return m2_base_utf8_to_utf16(
		reinterpret_cast<const char*>(LockResource(
			LoadResource(Module, Resource))) + 2);
}

int main()
{
	

	wprintf(L"%s", NSudoGetUTF8StringResources(IDR_CommandLineHelpPage).c_str());
	
	return 0;
}

