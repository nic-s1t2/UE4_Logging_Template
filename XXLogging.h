// Copyright S1T2 2020

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(XXLog, Log, All);

namespace XXLogging
{
	enum ELoggingVerbosity : uint8
	{
		NoLogging = 0x00,
		Errors = 0x01,
		Warnings = 0x02,
		All = 0x03
	};

	static ELoggingVerbosity LogVerbosity = ELoggingVerbosity::All;

	void Message(UObject* Context, FString Message, bool bLogOnScreen = false, FColor Color = FColor::White);
	void Warning(UObject* Context, FString Message, bool bLogOnScreen = true, FColor Color = FColor::Yellow);
	void Error(UObject* Context, FString Message, bool bLogOnScreen = true, FColor Color = FColor::Red);

	void LogOnScreen(UObject* Context, FString Message, FColor Color);
}

UCLASS()
class XXXXXXXX_API UXXLogging : public UObject
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, meta = (Category = "XXLogging", WorldContext = "Context"))
	static void LogMessage(UObject* Context, FString Message, bool bLogOnScreen = false, FLinearColor Color = FLinearColor::White);

	UFUNCTION(BlueprintCallable, meta = (Category = "XXLogging", WorldContext = "Context"))
	static void LogWarning(UObject* Context, FString Message, bool bLogOnScreen = true, FLinearColor Color = FLinearColor::Yellow);

	UFUNCTION(BlueprintCallable, meta = (Category = "XXLogging", WorldContext = "Context"))
	static void LogError(UObject* Context, FString Message, bool bLogOnScreen = true, FLinearColor Color = FLinearColor::Red);

};
