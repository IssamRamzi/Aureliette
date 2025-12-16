#include "Globals.h"

class Camera;
class GLShader;
class Mesh;

class Renderer{

public:

    enum class RendererMode{
        Fill,
        Wireframe
    };

public:

    Renderer();
    ~Renderer();

    void Initialize();

    void BeginFrame(const vec3_f& clearColor = {0.2f, 0.3f, 0.3f});

    void SetViewport(int x, int y, int width, int height);
    void GetViewport(int& x, int& y, int& width, int& height) const;

    void SetCamera(Camera* camera);
    Camera* GetCamera() const {return m_camera;}
    
    void UseShader(GLShader* shader);
    GLShader* GetCurrentShader() const {return m_currentShader;}
    

    // Rendering ops
    void DrawMesh(Mesh* mesh, const mat4_f& modelMatrix);
    void DrawModel(Mesh* model, const mat4_f& modelMatrix);

    void ClearColor(vec3_f color);


    // State management
    void SetRendererMode(RendererMode mode);
    RendererMode GetRendererMode() const {return m_rendererMode;}

private:

    Camera *m_camera;
    GLShader *m_currentShader;
    RendererMode m_rendererMode;
    

    int m_viewportX, m_viewportY, m_viewportWidth, m_viewportHeight;


    

};