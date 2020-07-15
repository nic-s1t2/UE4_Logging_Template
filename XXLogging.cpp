// Copyright S1T2 2020

#include "XXLogging.h"

DEFINE_LOG_CATEGORY(XXLog);

void XXLogging::Message(UObject* Context, FString Message, bool bLogOnScreen, FColor Color)
{
	if (LogVerbosity == ELoggingVerbosity::All)
	{
		UE_LOG(XXLog, Display, TEXT("%s: %s"), *Context->GetName(), *Message);
		if (bLogOnScreen)
		{
			LogOnScreen(Context, Message, Color);
		}
	}
}

void XXLogging::Warning(UObject* Context, FString Message, bool bLogOnScreen, FColor Color)
{
	if (LogVerbosity >= ELoggingVerbosity::Warnings)
	{
		UE_LOG(XXLog, Warning, TEXT("%s: %s"), *Context->GetName(), *Message);
		if (bLogOnScreen)
		{
			LogOnScreen(Context, "Warning: " + Message, Color);
		}
	}
}

void XXLogging::Error(UObject* Context, FString Message, bool bLogOnScreen, FColor Color)
{
	if (LogVerbosity >= ELoggingVerbosity::Errors)
	{
		UE_LOG(XXLog, Error, TEXT("%s: %s"), *Context->GetName(), *Message);
		if (bLogOnScreen)
		{
			LogOnScreen(Context, "Error: " + Message, Color);
		}
	}
}

void XXLogging::LogOnScreen(UObject* Context, FString Message, FColor Color)
{
	FString Msg = Context->GetName();
	Msg += ": ";
	Msg += Message;

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, Color, *Msg);
}

void UXXLogging::LogMessage(UObject* Context, FString Message, bool bLogOnScreen /*= false*/, FLinearColor Color /*= FColor::White*/)
{
	XXLogging::Message(Context, Message, bLogOnScreen, Color.ToFColor(false));
}

void UXXLogging::LogWarning(UObject* Context, FString Message, bool bLogOnScreen /*= true*/, FLinearColor Color /*= FColor::Yellow*/)
{
	XXLogging::Warning(Context, Message, bLogOnScreen, Color.ToFColor(false));
}

void UXXLogging::LogError(UObject* Context, FString Message, bool bLogOnScreen /*= true*/, FLinearColor Color /*= FColor::Red*/)
{
	XXLogging::Error(Context, Message, bLogOnScreen, Color.ToFColor(false));
}
