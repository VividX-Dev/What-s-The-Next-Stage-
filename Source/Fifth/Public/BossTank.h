// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fifth.h"
#include "GameFramework/Character.h"
#include "BossTank.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAttackEndDelegate);

UCLASS()
class FIFTH_API ABossTank : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABossTank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void SetControlMode(int32 ControlMode);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class
		AController* EventInstigator, AActor* DamageCauser) override;
	virtual void PossessedBy(AController* NewController) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	void Attack();
	void Damaged();
	void Kick();
	void Skill();
	void SpecialAttack();
	void Screaming();

	UPROPERTY(VisibleAnywhere, Category = Stat)
		class UBossStatComponent* BossStat;

	FOnAttackEndDelegate OnAttackEnd;

private:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		bool IsAttacking;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		bool IsDamaging;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		bool IsKicking;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		bool IsSkillUsing;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		bool IsSpecialAttacking;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		bool IsScreaming;
	
	void AttackCheck();
	void KickCheck();
	void SkillCheck();

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRange;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRadius;

	UPROPERTY()
		class UBossTankAnimInstance* BTAnim;

	UFUNCTION()
		void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
		void OnDamagedMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
		void OnKickMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
		void OnSkillMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
		void OnSpecialMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
		void OnScreamMontageEnded(UAnimMontage* Montage, bool bInterrupted);

};
