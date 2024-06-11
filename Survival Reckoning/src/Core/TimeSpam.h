#ifndef TIME_H
#define TIME_H

namespace SRMM
{
	class TimeSpam
	{
	public:
		TimeSpam(float delta)
			: mDeltaTime(delta) {}

		float GetSeconds() { return mDeltaTime; }
		float GetMilli() { return mDeltaTime * 1000.0f; }

	private:
		float mDeltaTime;
	};
}

#endif