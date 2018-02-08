#include "ALSource.h"

#include <OpenAL/al.h>

#include "ALBuffer.h"

namespace vt {

	ALSource::ALSource() : m_source(0)
	{
	}

	ALSource::~ALSource()
	{
	}

	void ALSource::initialize()
	{
		alGenSources(1, &m_source);
		alSourcef(m_source, AL_GAIN, 1.0f);
		alSourcef(m_source, AL_PITCH, 1.0f);
	}

	void ALSource::cleanup()
	{
		stop();
		alDeleteSources(1, &m_source);
	}

	void ALSource::play(const ALBuffer& buffer)
	{
		alSourcei(m_source, AL_BUFFER, buffer.m_buffer);
		alSourcePlay(m_source);
	}

	void ALSource::stop()
	{
		alSourceStop(m_source);
	}

	void ALSource::setLooping(bool looping)
	{
		alSourcei(m_source, AL_LOOPING, looping ? AL_TRUE : AL_FALSE);
	}

	void ALSource::setPosition(const f32v3& position)
	{
		alSource3f(m_source, AL_POSITION, position.x, position.y, position.z);
	}

	void ALSource::setVelocity(const f32v3& velocity)
	{
		alSource3f(m_source, AL_VELOCITY, velocity.x, velocity.y, velocity.z);
	}

}