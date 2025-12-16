class Time
{
private:
    static float m_fps;
    static int   m_numFrames;

    static float m_deltaTime;
    static float m_lastFrameTime;
    static float m_fpsTimer;

public:
    static void Init();
    static void Update();

    static float GetDeltaTime() { return m_deltaTime; }
    static float GetFPS()       { return m_fps; }
};
