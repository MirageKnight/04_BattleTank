// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

void UTankTrack::SetThrtottle(float Throttle) {

	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle = %f"), *Name, Throttle);

	// ForwardVector is the direction, throttle is percent of max force, and multiplied by max force
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


