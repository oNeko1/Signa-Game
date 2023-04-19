/**
 CPhysics2D
 @brief A class to calculate SUVAT equations for the game
 By: Toh Da Jun
 Date: Mar 2020
 */
#pragma once

#include <includes/glm.hpp>
#include <includes/gtc/matrix_transform.hpp>
#include <includes/gtc/type_ptr.hpp>

class CPhysics2D
{
public:
	enum STATUS
	{
		IDLE = 0,
		JUMP,
		FALL,
		NUM_STATUS
	};

	// Constructor
	CPhysics2D(void);

	// Destructor
	virtual ~CPhysics2D(void);

	// Init
	bool Init(void);

	// Set methods
	void SetInitialVelocity(const glm::vec2 v2InitialVelocity);	// Set Initial velocity
	void SetFinalVelocity(const glm::vec2 v2FinalVelocity);		// Set Final velocity
	void SetAcceleration(const glm::vec2 v2Acceleration);		// Set Acceleration
	void SetDisplacement(const glm::vec2 v2Displacement);		// Set Displacement
	void SetElapsedTime(const double dElapsedTime);				// Set Elapsed Time
	void SetStatus(const STATUS sStatus);						// Set Status

	// Get methods
	glm::vec2 GetInitialVelocity(void) const;	// Get Initial velocity
	glm::vec2 GetFinalVelocity(void) const;		// Get Final velocity
	glm::vec2 GetAcceleration(void) const;		// Get Acceleration
	glm::vec2 GetDisplacement(void) const;		// Get Displacement
	glm::vec2 GetDeltaDisplacement(void) const;	// Get Delta Displacement
	double GetElapsedTime(void) const;			// Get Elapsed Time
	STATUS GetStatus(void) const;				// Get Status

	// Update
	bool Update(const double dElapsedTime);

	// Calculate the distance between two vec2 varables
	float CalculateDistance(glm::vec2 source, glm::vec2 destination);

	// PrintSelf
	void PrintSelf(void);

protected:
	// Variables for SUVAT calculations
	glm::vec2 v2InitialVelocity;	// Initial velocity
	glm::vec2 v2FinalVelocity;		// Final velocity
	glm::vec2 v2Acceleration;		// Acceleration
	glm::vec2 v2Displacement;		// Displacement
	glm::vec2 v2PrevDisplacement;	// Previous Displacement
	double dElapsedTime;			// Elapsed Time since the last update

	const glm::vec2 v2Gravity = glm::vec2( 0.0f, -10.0f);		// Gravity constant

	STATUS sCurrentStatus;
};

