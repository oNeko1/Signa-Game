/**
 CPhysics2D
 @brief A class to calculate SUVAT equations for the game
 By: Toh Da Jun
 Date: Mar 2020
 */
#include "Physics2D.h"

#include <iostream>
using namespace std;

/**
 @brief Constructor This constructor has protected access modifier as this class will be a Singleton
 */
CPhysics2D::CPhysics2D(void)
	: v2InitialVelocity(glm::vec2(0.0f))
	, v2FinalVelocity(glm::vec2(0.0f))
	, v2Acceleration(glm::vec2(0.0f))
	, v2Displacement(glm::vec2(0.0f))
	, v2PrevDisplacement(glm::vec2(0.0f))
	, dElapsedTime(0.0)
	, sCurrentStatus(STATUS::IDLE)
{
}

/**
 @brief Destructor This destructor has protected access modifier as this class will be a Singleton
 */
CPhysics2D::~CPhysics2D(void)
{
}

/**
@brief Init Initialise this instance
@return A bool variable to indicate this method successfully completed its tasks
*/ 
bool CPhysics2D::Init(void)
{
	// Reset these variables
	v2InitialVelocity = glm::vec2(0.0f);
	v2FinalVelocity = glm::vec2(0.0f);
	//v2Acceleration = glm::vec2(0.0f);		// Acceleration does not need to be reset here.
	v2Displacement = glm::vec2(0.0f);
	v2PrevDisplacement = glm::vec2(0.0f);
	dElapsedTime = 0.0;
	return true;
}

// Set methods
/**
 @brief Set Initial velocity
 @param v2InitialVelocity A const glm::vec2 variable containing the initial velocity
 */ 
void CPhysics2D::SetInitialVelocity(const glm::vec2 v2InitialVelocity)
{
	this->v2InitialVelocity = v2InitialVelocity;	// Initial velocity
}

/**
 @brief Set Final velocity
 @param v2FinalVelocity A const glm::vec2 variable containing the final velocity
 */
 void CPhysics2D::SetFinalVelocity(const glm::vec2 v2FinalVelocity)
{
	this->v2FinalVelocity = v2FinalVelocity;		// Final velocity
}

/**
 @brief Set Acceleration
 @param v2Acceleration A const glm::vec2 variable containing the acceleration
 */
void CPhysics2D::SetAcceleration(const glm::vec2 v2Acceleration)
{
	this->v2Acceleration = v2Acceleration;		// Acceleration
}

/**
 @brief Set Displacement
 @param v2Displacement A const glm::vec2 variable containing the displacement
 */
void CPhysics2D::SetDisplacement(const glm::vec2 v2Displacement)
{
	this->v2Displacement = v2Displacement;		// Displacement
}

/**
 @brief Reset Elapsed Time
 @param fTime A const float variable containing the time
 */
void CPhysics2D::SetElapsedTime(const double dElapsedTime)
{
	this->dElapsedTime = dElapsedTime;					// Elapsed Time
}

/**
 @brief Set Status
 @param sStatus A const STATUS variable containing the new status
 */
void CPhysics2D::SetStatus(const STATUS sStatus)
{
	// If there is a change in status, then reset to default values
	if (sCurrentStatus != sStatus)
	{
		// Reset to default values
		Init();

		// Store the new status
		sCurrentStatus = sStatus;
	}
}

// Get methods
/**
 @brief Get Initial velocity
 @return A glm::vec2 variable containing the initial velocity
 */
glm::vec2 CPhysics2D::GetInitialVelocity(void) const
{
	return v2InitialVelocity;	// Initial velocity
}

/**
 @brief Get Final velocity
 @return A glm::vec2 variable containing the Final velocity
 */
glm::vec2 CPhysics2D::GetFinalVelocity(void) const
{
	return v2FinalVelocity;		// Final velocity
}

/**
 @brief Get Acceleration
 @return A glm::vec2 variable containing the Acceleration
 */ 
glm::vec2 CPhysics2D::GetAcceleration(void) const
{
	return v2Acceleration;		// Acceleration
}

/**
 @brief Get Displacement
 @return A glm::vec2 variable containing the Displacement
 */
glm::vec2 CPhysics2D::GetDisplacement(void) const
{
	return v2Displacement;		// Displacement
}

/**
 @brief Get Delta Displacement
 @return A glm::vec2 variable containing the Delta Displacement
 */
glm::vec2 CPhysics2D::GetDeltaDisplacement(void) const
{
	return v2Displacement - v2PrevDisplacement;		// Delta Displacement
}

/**
 @brief Get Elapsed Time
 @return A float variable containing the elapsed time
 */ 
double CPhysics2D::GetElapsedTime(void) const
{
	return dElapsedTime;					// dElapsedTime
}

/**
 @brief Get Status
 @return A CPhysics2D::STATUS variable containing the current status
 */ 
CPhysics2D::STATUS CPhysics2D::GetStatus(void) const
{
	return sCurrentStatus;
}

/**
 @brief Update the Physics values
 @param dElapsedTime A const double variable containing the dElapsedTime
 */
bool CPhysics2D::Update(const double dElapsedTime)
{
	// Update the dElapsedTime variable in this class
	SetElapsedTime(dElapsedTime);

	// If the player is in IDLE mode, 
	// then we don't calculate further
	if (sCurrentStatus == IDLE)
		return false;

	// Store the previous displacement values
	v2PrevDisplacement = v2Displacement;

	// Calculate the final velocity
	v2FinalVelocity = v2InitialVelocity + float(dElapsedTime) * v2Gravity;
	// Calculate the change in position
	v2Displacement = float(dElapsedTime) * v2FinalVelocity;

	// Store the initial velocity to the final velocity
	v2InitialVelocity = v2FinalVelocity;

	return true;
}

/**
 @brief 
 */
 // Calculate the distance between two vec2 varables
float CPhysics2D::CalculateDistance(glm::vec2 source, glm::vec2 destination)
{
	return glm::length(destination - source);
}

/**
 @brief PrintSelf
 */
void CPhysics2D::PrintSelf(void)
{
	cout << "CPhysics2D::PrintSelf()" << endl;
	cout << "=======================" << endl;
	cout << "v2InitialVelocity\t=\t" << v2InitialVelocity.x << ", " << v2InitialVelocity.y << endl;
	cout << "v2FinalVelocity\t=\t" << v2FinalVelocity.x << ", " << v2FinalVelocity.y << endl;
	cout << "v2Acceleration\t=\t" << v2Acceleration.x << ", " << v2Acceleration.y << endl;
	cout << "v2Displacement\t=\t" << v2Displacement.x << ", " << v2Displacement.y << endl;
	cout << "dElapsedTime\t=\t" << dElapsedTime << endl;
}
