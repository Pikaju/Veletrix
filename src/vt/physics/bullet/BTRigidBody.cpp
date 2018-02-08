#include "BTRigidBody.h"

#include <Bullet/btBulletDynamicsCommon.h>

#include "BTPhysicsWorld.h"

namespace vt {

	BTRigidBody::BTRigidBody()
	{
	}

	BTRigidBody::~BTRigidBody()
	{
	}

	void BTRigidBody::initialize(BTCollisionShape& shape, const f32t& transform, f32 mass)
	{
		m_shape = shape.getBulletCollisionShape();
		btVector3 localInertia;
		if (mass != INFINITE_MASS) {
			m_shape->calculateLocalInertia(mass, localInertia);
		}
		btTransform trans(btQuaternion(transform.rotation.x, transform.rotation.y, transform.rotation.z, transform.rotation.w), btVector3(transform.origin.x, transform.origin.y, transform.origin.z));
		m_body = new btRigidBody(btRigidBody::btRigidBodyConstructionInfo(mass, new btDefaultMotionState(trans), m_shape, localInertia));
	}

	void BTRigidBody::cleanup()
	{
		m_world->removeRigidBody(this);
		delete m_body->getMotionState();
		delete m_body;
		delete m_shape;
	}

	f32v3 BTRigidBody::getOrigin() const
	{
		btTransform& transform = m_body->getWorldTransform();
		return f32v3(transform.getOrigin().getX(), transform.getOrigin().getY(), transform.getOrigin().getZ());
	}

	f32q BTRigidBody::getRotation() const
	{
		btQuaternion quaternion = m_body->getWorldTransform().getRotation();
		return f32q(quaternion.getX(), quaternion.getY(), quaternion.getZ(), quaternion.getW());
	}

	f32v3 BTRigidBody::getVelocity() const
	{
		const btVector3& v = m_body->getLinearVelocity();
		return f32v3(v.getX(), v.getY(), v.getZ());
	}

	f32m4 BTRigidBody::getTransformationMatrix() const
	{
		f32m4 matrix = f32m4::identity();
		btTransform& transform = m_body->getWorldTransform();
		transform.getOpenGLMatrix(matrix.getPointer());
		return matrix;
	}

	void BTRigidBody::setOrigin(const f32v3& origin)
	{
		m_body->getWorldTransform().setOrigin(btVector3(origin.x, origin.y, origin.z));
	}

	void BTRigidBody::setRotation(const f32q& rotation)
	{
		m_body->getWorldTransform().setRotation(btQuaternion(rotation.x, rotation.y, rotation.z, rotation.w));
	}

	void BTRigidBody::setVelocity(const f32v3& velocity)
	{
		m_body->setLinearVelocity(btVector3(velocity.x, velocity.y, velocity.z));
	}

	void BTRigidBody::applyCentralForce(const f32v3& force)
	{
		m_body->applyCentralForce(btVector3(force.x, force.y, force.z));
	}

	void BTRigidBody::applyCentralImpulse(const f32v3& impulse)
	{
		m_body->applyCentralImpulse(btVector3(impulse.x, impulse.y, impulse.z));
	}

	void BTRigidBody::setAngularFactor(f32 angularFactor)
	{
		m_body->setAngularFactor(angularFactor);
	}

	void BTRigidBody::setDamping(f32 linear, f32 angular)
	{
		m_body->setDamping(linear, angular);
	}

	void BTRigidBody::setActivationState(ActivationState activationState)
	{
		switch (activationState) {
		case ACTIVATION_STATE_DEFAULT: m_body->setActivationState(ACTIVE_TAG); break;
		case ACTIVATION_STATE_ALWAYS_ACTIVE: m_body->setActivationState(DISABLE_DEACTIVATION); break;
		case ACTIVATION_STATE_ALWAYS_DISABLED: m_body->setActivationState(DISABLE_SIMULATION); break;
		}
	}

}