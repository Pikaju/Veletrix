#pragma once

#include "../../Build.h"
#include "shape/BTCollisionShape.h"
#include "../../math/Transform.h"
#include "ActivationState.h"

class btRigidBody;
class btCollisionShape;

namespace vt {

	static const f32 INFINITE_MASS = 0.0f;

	class BTPhysicsWorld;

	class VT_API BTRigidBody
	{
		friend class BTPhysicsWorld;
	public:
		BTRigidBody();
		~BTRigidBody();

		void initialize(BTCollisionShape& shape, const f32t& transform, f32 mass);
		void cleanup();

		f32v3 getOrigin() const;
		f32q getRotation() const;
		f32v3 getVelocity() const;
		f32m4 getTransformationMatrix() const;
		void setOrigin(const f32v3& origin);
		void setRotation(const f32q& rotation);
		void setVelocity(const f32v3& velocity);

		void applyCentralForce(const f32v3& force);
		void applyCentralImpulse(const f32v3& impulse);

		void setAngularFactor(f32 angularFactor);
		void setDamping(f32 linear, f32 angular);

		void setActivationState(ActivationState activationState);

		inline BTPhysicsWorld* getWorld() { return m_world; }
	private:
		BTPhysicsWorld* m_world;
		btRigidBody* m_body;
		btCollisionShape* m_shape;
	};

}