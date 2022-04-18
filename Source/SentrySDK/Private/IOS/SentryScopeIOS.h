// Copyright (c) 2022 Sentry. All Rights Reserved.

#pragma once

#include "Interface/SentryScopeInterface.h"

@class SentryScope;

class SentryScopeIOS : public ISentryScope
{
public:
	SentryScopeIOS();
	SentryScopeIOS(SentryScope* scope);
	virtual ~SentryScopeIOS() override;

	SentryScope* GetNativeObject();

	virtual void SetTagValue(const FString& key, const FString& value) override;
	virtual FString GetTagValue(const FString& key) const override;
	virtual void RemoveTag(const FString& key) override;
	virtual void SetTags(const TMap<FString, FString>& tags) override;
	virtual TMap<FString, FString> GetTags() const override;
	virtual void SetDist(const FString& dist) override;
	virtual FString GetDist() const override;
	virtual void SetEnvironment(const FString& environment) override;
	virtual FString GetEnvironment() const override;
	virtual void SetFingerprint(const TArray<FString>& fingerprint) override;
	virtual TArray<FString> GetFingerprint() const override;
	virtual void SetLevel(ESentryLevel level) override;
	virtual ESentryLevel GetLevel() const override;
	virtual void Clear() override;

private:
	SentryScope* ScopeIOS;
};
