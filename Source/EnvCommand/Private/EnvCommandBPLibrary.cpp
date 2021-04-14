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
	char* ValueChars = getenv(StdString(Name).c_str());
	FString Value = TEXT("");

	if (ValueChars != NULL) 
	{
		Value = ValueChars;
	}

	return Value;
}

int32 UEnvCommandBPLibrary::SetEnvironmentVariable(const FString& Name, const FString& Value)
{
	FString Combined = Name + TEXT("=") + Value;
	return putenv(StdString(Combined).c_str());
}