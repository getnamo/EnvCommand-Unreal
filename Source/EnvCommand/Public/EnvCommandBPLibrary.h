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

	UFUNCTION(BlueprintCallable, Category="EnvCommand")
	static FString GetEnvironmentVariable(const FString& Name);


	UFUNCTION(BlueprintCallable, Category = "EnvCommand")
	static int32 SetEnvironmentVariable(const FString& Name, const FString& Value);

private:

};
