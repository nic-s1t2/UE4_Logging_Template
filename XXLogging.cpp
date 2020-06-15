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
