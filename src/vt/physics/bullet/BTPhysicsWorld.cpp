#include "BTPhysicsWorld.h"

#include <Bullet/btBulletDynamicsCommon.h>

#include "BTRigidBody.h"

namespace vt {

	BTPhysicsWorld::BTPhysicsWorld()
	{
	}

	BTPhysicsWorld::~BTPhysicsWorld()
	{
	}

	void BTPhysicsWorld::initialize()
	{
		m_broadphase = new btDbvtBroadphase();
		m_collisionConfiguration = new btDefaultCollisionConfiguration();
		m_dispatcher = new btCollisionDispatcher(m_collisionConfiguration);
		m_solver = new btSequentialImpulseConstraintSolver();
		m_world = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase, m_solver, m_collisionConfiguration);
		setGravity(f32v3());
	}

	void BTPhysicsWorld::cleanup()
	{
		delete m_world;
		delete m_solver;
		delete m_dispatcher;
		delete m_collisionConfiguration;
		delete m_broadphase;
	}

	void BTPhysicsWorld::step(f32 delta, ui32f maximumSteps)
	{
		m_world->stepSimulation(delta, maximumSteps);
	}

	void BTPhysicsWorld::addRigidBody(BTRigidBody* body)
	{
		body->m_world = this;
		m_world->addRigidBody(body->m_body);
	}

	void BTPhysicsWorld::removeRigidBody(BTRigidBody* body)
	{
		m_world->removeRigidBody(body->m_body);
	}

	void BTPhysicsWorld::setGravity(const f32v3& gravity)
	{
		m_world->setGravity(btVector3(gravity.x, gravity.y, gravity.z));
	}

	BTRayResult BTPhysicsWorld::rayCastClosest(const f32v3& rayStart, const f32v3& rayEnd)
	{
		btVector3 start(rayStart.x, rayStart.y, rayStart.z);
		btVector3 end(rayEnd.x, rayEnd.y, rayEnd.z);
		btCollisionWorld::ClosestRayResultCallback result(start, end);
		m_world->rayTest(start, end, result);
		return BTRayResult(result.hasHit(), f32v3(result.m_hitPointWorld.x(), result.m_hitPointWorld.y(), result.m_hitPointWorld.z()), f32v3(result.m_hitNormalWorld.x(), result.m_hitNormalWorld.y(), result.m_hitNormalWorld.z()));
	}

	BTRayResult BTPhysicsWorld::rayCastClosestNotMe(const BTRigidBody* body, const f32v3& rayStart, const f32v3& rayEnd)
	{
		btVector3 start(rayStart.x, rayStart.y, rayStart.z);
		btVector3 end(rayEnd.x, rayEnd.y, rayEnd.z);
		btCollisionWorld::ClosestRayResultCallback result(start, end);
		m_world->rayTest(start, end, result);
		return BTRayResult(result.hasHit(), f32v3(result.m_hitPointWorld.x(), result.m_hitPointWorld.y(), result.m_hitPointWorld.z()), f32v3(result.m_hitNormalWorld.x(), result.m_hitNormalWorld.y(), result.m_hitNormalWorld.z()));
	}

}