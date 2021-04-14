// Copyright 2021-current Getnamo. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EnvCommandBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ENVCOMMAND_API UEnvCommandBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/**
	* Gets current environment value for name. If you use e.g. $HOME just enter HOME for the Name
	*/
	UFUNCTION(BlueprintCallable, Category="EnvCommand")
	static FString GetEnvironmentVariable(const FString& Name);

	/** 
	* Sets specified value for name in current environment. 
	* If you use e.g. $HOME just enter HOME for the Name.
	* Returns 0 if successful (copies std lib api)
	*/
	UFUNCTION(BlueprintCallable, Category = "EnvCommand")
	static int32 SetEnvironmentVariable(const FString& Name, const FString& Value);

};
