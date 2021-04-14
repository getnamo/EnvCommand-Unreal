// Copyright 2021-current Getnamo. All Rights Reserved

#include "EnvCommandBPLibrary.h"
#include <stdlib.h>
#include <string>

namespace 
{
	std::string StdString(FString UEString)
	{
		return std::string(TCHAR_TO_UTF8(*UEString));
	}

	FString FStringFromStd(std::string StdString)
	{
		return FString(UTF8_TO_TCHAR(StdString.c_str()));
	}
}

FString UEnvCommandBPLibrary::GetEnvironmentVariable(const FString& Name)
{
	FString Value = TEXT("");

#if PLATFORM_WINDOWS
	char* Buffer;
	size_t Size;
	if (_dupenv_s(&Buffer, &Size, StdString(Name).c_str()) == 0 && Buffer != nullptr)
	{
		Value = Buffer;
		free(Buffer);
	}
#else
	char* ValueChars = getenv(StdString(Name).c_str());

	if (ValueChars != NULL) 
	{
		Value = ValueChars;
	}
#endif

	return Value;
}

int32 UEnvCommandBPLibrary::SetEnvironmentVariable(const FString& Name, const FString& Value)
{
	FString Combined = Name + TEXT("=") + Value;
#if PLATFORM_WINDOWS
	return _putenv(StdString(Combined).c_str());
#else
	return putenv(StdString(Combined).c_str());
#endif
}