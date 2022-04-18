// Copyright (c) 2022 Sentry. All Rights Reserved.

#include "SentryScope.h"
#include "Interface/SentryScopeInterface.h"

#if PLATFORM_ANDROID
#include "Android/SentryScopeAndroid.h"
#endif

#if PLATFORM_IOS
#include "IOS/SentryScopeIOS.h"
#endif

USentryScope::USentryScope()
{
	if (USentryScope::StaticClass()->GetDefaultObject() != this)
	{
#if PLATFORM_ANDROID
		ScopeNativeImpl = MakeShareable(new SentryScopeAndroid());
#endif
#if PLATFORM_IOS
		ScopeNativeImpl = MakeShareable(new SentryScopeIOS());
#endif
	}
}

void USentryScope::SetTagValue(const FString& Key, const FString& Value)
{
	if (!ScopeNativeImpl)
		return;

	ScopeNativeImpl->SetTagValue(Key, Value);
}

FString USentryScope::GetTagValue(const FString& Key) const
{
	if (!ScopeNativeImpl)
		return FString();

	return ScopeNativeImpl->GetTagValue(Key);
}

void USentryScope::RemoveTag(const FString& Key)
{
	if (!ScopeNativeImpl)
		return;

	ScopeNativeImpl->RemoveTag(Key);
}

void USentryScope::SetTags(const TMap<FString, FString>& Tags)
{
	if (!ScopeNativeImpl)
		return;

	ScopeNativeImpl->SetTags(Tags);
}

TMap<FString, FString> USentryScope::GetTags() const
{
	if (!ScopeNativeImpl)
		return TMap<FString, FString>();

	return ScopeNativeImpl->GetTags();
}

void USentryScope::SetDist(const FString& Dist)
{
	if (!ScopeNativeImpl)
		return;

	ScopeNativeImpl->SetDist(Dist);
}

FString USentryScope::GetDist() const
{
	if (!ScopeNativeImpl)
		return FString();

	return ScopeNativeImpl->GetDist();
}

void USentryScope::SetEnvironment(const FString& Environment)
{
	if (!ScopeNativeImpl)
		return;

	ScopeNativeImpl->SetEnvironment(Environment);
}

FString USentryScope::GetEnvironment() const
{
	if (!ScopeNativeImpl)
		return FString();

	return ScopeNativeImpl->GetEnvironment();
}

void USentryScope::SetFingerprint(const TArray<FString>& Fingerprint)
{
	if (!ScopeNativeImpl)
		return;

	ScopeNativeImpl->SetFingerprint(Fingerprint);
}

TArray<FString> USentryScope::GetFingerprint() const
{
	if (!ScopeNativeImpl)
		return TArray<FString>();

	return ScopeNativeImpl->GetFingerprint();
}

void USentryScope::SetLevel(ESentryLevel Level)
{
	if (!ScopeNativeImpl)
		return;

	ScopeNativeImpl->SetLevel(Level);
}

ESentryLevel USentryScope::GetLevel() const
{
	if(!ScopeNativeImpl)
		return ESentryLevel::Debug;

	return ScopeNativeImpl->GetLevel();
}

void USentryScope::Clear()
{
	if (!ScopeNativeImpl)
		return;

	ScopeNativeImpl->Clear();
}

void USentryScope::InitWithNativeImpl(TSharedPtr<ISentryScope> scopeImpl)
{
	if (!ScopeNativeImpl)
		return;

	ScopeNativeImpl = scopeImpl;
}

TSharedPtr<ISentryScope> USentryScope::GetNativeImpl()
{
	return ScopeNativeImpl;
}
