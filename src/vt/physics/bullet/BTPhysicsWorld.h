#pragma once

#include "../../Build.h"
#include "BTRayResult.h"

class btDiscreteDynamicsWorld;
class btBroadphaseInterface;
class btDefaultCollisionConfiguration;
class btCollisionDispatcher;
class btSequentialImpulseConstraintSolver;

namespace vt {

	class BTRigidBody;

	class VT_API BTPhysicsWorld
	{
	public:
		BTPhysicsWorld();
		~BTPhysicsWorld();

		void initialize();
		void cleanup();

		void step(f32 delta, ui32f maximumSteps);

		void addRigidBody(BTRigidBody* body);
		void removeRigidBody(BTRigidBody* body);

		void setGravity(const f32v3& gravity);

		BTRayResult rayCastClosest(const f32v3& rayStart, const f32v3& rayEnd);
		BTRayResult rayCastClosestNotMe(const BTRigidBody* body, const f32v3& rayStart, const f32v3& rayEnd);
	private:
		btDiscreteDynamicsWorld* m_world;
		btBroadphaseInterface* m_broadphase;
		btDefaultCollisionConfiguration* m_collisionConfiguration;
		btCollisionDispatcher* m_dispatcher;
		btSequentialImpulseConstraintSolver* m_solver;
	};

}